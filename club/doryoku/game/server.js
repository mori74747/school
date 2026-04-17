const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');

// ポート番号の設定（環境変数PORTがなければ3000番を使用）
const PORT = process.env.PORT || 3000;

const app = express();
const httpServer = http.createServer(app);
const io = new Server(httpServer);

// --- 静的ファイルサーバーの設定 ---
// カレントディレクトリ（index.htmlやgame.jsがある場所）を公開し、
// ブラウザからアクセスできるようにします。
app.use(express.static(path.join(__dirname)));

// --- ゲーム状態（サーバー側で保持するデータ） ---

// players: 接続中の全プレイヤーの情報を格納するオブジェクト
// 構造: { [socketId]: { x, y, z, pitch, yaw, health } }
const players = {};

// blocksModified: 改変されたブロックの情報を記録するMap
// キー: "x,y,z" の文字列 => 値: ブロックの種類（0なら破壊済み）
// これにより、後から参加したプレイヤーにも「誰かが壊した跡」を同期できます。
const blocksModified = new Map();

// --- 通信ハンドラー（クライアントが接続したときの処理） ---
io.on('connection', (socket) => {
    console.log(`[+] プレイヤーが接続しました: ${socket.id}`);

    // 新規プレイヤーの初期状態を設定
    players[socket.id] = {
        x: 0,
        y: 15.0, // 少し高い位置からスポーン
        z: 0,
        pitch: 0,
        yaw: 0,
        health: 100,
    };

    // 1. 接続してきた本人に、現在ログイン中の全プレイヤー情報を送る
    socket.emit('currentPlayers', players);

    // 2. 途中参加のプレイヤーに、これまでのブロック変更履歴をすべて送る
    // Mapを配列に変換して送信します
    if (blocksModified.size > 0) {
        socket.emit('initialBlocks', Array.from(blocksModified.entries()));
    }

    // 3. 他の全員に「新しいプレイヤーが来た」ことを通知する
    socket.broadcast.emit('newPlayer', {
        id: socket.id,
        player: players[socket.id]
    });

    // --- 各種イベント受信時の処理 ---

    // プレイヤーの移動と視点移動の同期
    socket.on('playerMovement', (movementData) => {
        if (players[socket.id]) {
            // サーバー側のデータを更新
            players[socket.id].x = movementData.x;
            players[socket.id].y = movementData.y;
            players[socket.id].z = movementData.z;
            players[socket.id].pitch = movementData.pitch;
            players[socket.id].yaw = movementData.yaw;
            // 全プレイヤーに最新の位置をブロードキャスト（送信者以外）
            socket.broadcast.emit('playerMoved', {
                id: socket.id,
                x: movementData.x,
                y: movementData.y,
                z: movementData.z,
                pitch: movementData.pitch,
                yaw: movementData.yaw
            });
        }
    });

    // ブロックの設置・破壊の同期
    socket.on('blockUpdate', (data) => {
        // 例: { x: 1, y: 2, z: 3, type: 0 }
        const key = `${data.x},${data.y},${data.z}`;
        blocksModified.set(key, data.type);
        // ブロックの置き換わりを伝える
        io.emit('blockChanged', data);
    });

    // 矢が放たれたときの同期
    socket.on('shootArrow', (arrowData) => {
        // 誰がどの方向に撃ったかを全員に拡散
        io.emit('arrowShot', {
            id: socket.id,
            ...arrowData
        });
    });

    // プレイヤーへのダメージ判定
    socket.on('hitPlayer', (data) => {
        const target = players[data.targetId];
        if (!target) return;

        target.health -= data.damage;
        // ダメージを受けた本人にのみ通知
        io.to(data.targetId).emit('takeDamage', { damage: data.damage });

        // 全員に、ターゲットのHPが更新されたことを通知
        io.emit('playerHealthUpdate', {
            id: data.targetId,
            health: target.health,
        });

        // 死亡時の処理（簡易リスポーン）
        if (target.health <= 0) {
            target.health = 100;
            target.x = 0; target.y = 15.0; target.z = 0;
            io.to(data.targetId).emit('respawn', { health: target.health });
        }
    });

    // エネミー（ゾンビ等）へのダメージ同期
    // 現在は、仮実装
    socket.on('damageEnemy', (data) => {
        // 全員に「この敵がダメージを受けた」と通知（game.js側でエフェクト等を出すため）
        io.emit('enemyDamaged', {
            enemyId: data.enemyId,
            damage: data.damage,
        });
    });

    // 接続切断時の処理
    socket.on('disconnect', () => {
        console.log(`[-] プレイヤーが切断しました: ${socket.id}`);
        // メモリから削除
        delete players[socket.id];
        // 全員に「プレイヤーの退出」を通知
        io.emit('playerDisconnected', socket.id);
    });
});

// サーバー起動
httpServer.listen(PORT, () => {
    console.log(`Server is running on http://localhost:${PORT}`);
});