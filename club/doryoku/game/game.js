import * as THREE from 'three';

// ============================================================
// ゲームエンジン初期化
// Three.jsのレンダラー・シーン・カメラ・ライトを設定する
// ============================================================

// HTMLの<canvas>要素を取得してWebGLレンダラーにセット
const canvas = document.getElementById('game-canvas');

// アンチエイリアスなしで高速描画するWebGLレンダラーを作成
const renderer = new THREE.WebGLRenderer({ canvas, antialias: false });
renderer.setSize(window.innerWidth, window.innerHeight);
renderer.setClearColor(0x7fccff, 1.0); // 空色（水色）で背景を塗りつぶす

// 3Dシーンとカメラを作成（視野角60度・アスペクト比は画面サイズに合わせる）
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(60, window.innerWidth / window.innerHeight, 0.1, 100);
camera.rotation.order = 'YXZ'; // ヨー→ピッチの順で回転させてカメラの上下左右を自然に

// 半球ライト: 空（白）と地面（灰）からの環境光
const hemiLight = new THREE.HemisphereLight(0xffffff, 0xaaaaaa, 1.1);
scene.add(hemiLight);

// 指向性ライト: 太陽光の代わり（斜め上から柔らかく照らす）
const dirLight1 = new THREE.DirectionalLight(0xfff5e6, 0.75);
dirLight1.position.set(1.5, 2.0, 1.0).normalize();
scene.add(dirLight1);

// ============================================================
// ブロック種類の定義
// ============================================================

const BLOCK_TYPES = {
    GRASS: { id: 1, name: 'grass' },
    DIRT: { id: 2, name: 'dirt' },
    STONE: { id: 3, name: 'stone' },
    WOOD: { id: 5, name: 'wood' },
    LEAVES: { id: 6, name: 'leaves' },
    WHITE_WALL: { id: 7, name: 'white_wall' }
};

// 設置可能なブロックID一覧
// 将来的に他のブロックも追加可能
const PLACEABLE_BLOCKS = [1, 2, 3, 5, 7];

// ============================================================
// グローバルゲーム状態
// ゲーム全体で使う変数をまとめて管理するオブジェクト
// ============================================================
const gameState = {
    isRunning: false,         // ゲームループが動いているかどうか
    player: {
        x: 0, y: 15.0, z: 0, // ワールド中央（中部屋）のスポーン位置
        pitch: 0, yaw: 0,    // カメラの上下（ピッチ）・左右（ヨー）の角度
        health: 100,
        selectedBlock: 1,     // 選択中のブロック種類: 1=草, 2=土, 3=石
        velocity: { x: 0, y: 0, z: 0 }, // 物理演算用の速度ベクトル
        isGrounded: true,     // 地面に接触しているか
        isDashing: false,     // ダッシュ中かどうか
        lastJumpTime: 0       // 壁ジャンプのクールダウン計測用
    },
    keys: {},                 // 現在押されているキーの状態テーブル { 'KeyW': true, ... }
    lastTime: 0,              // 前フレームのタイムスタンプ（deltaTime計算用）
    targetBlock: null,        // 現在カーソルが向いているブロック情報
    arrows: [],               // 飛行中の矢のリスト
    enemies: [],              // 敵エンティティのリスト
    isCharging: false,        // 弓を溜め中かどうか
    charge: 0,                // 弓の溜め量（0〜1.0）
    ammo: 20,                 // 残り矢数
    bowDurability: 64,        // 弓の耐久値（0になると使用不可）
    blockHealth: new Map(),   // ブロックごとのHPを管理 { "x,y,z": HP }
    miningProgress: 0,        // 現在のブロック採掘進捗（秒）
    miningTarget: null,       // 採掘中のブロック座標
    isMouseDown0: false,      // 左クリックが押されているか
    selectedSlot: 2,          // 選択中のホットバースロット（0〜7）
    inventory: [
        { type: 'bow', count: 1 },      // スロット0: 弓（特殊スロット）
        { type: 'arrow', count: 20 },   // スロット1: 矢（特殊スロット）
        { type: 'empty' },              // スロット2〜7: 通常アイテムスロット
        { type: 'empty' },
        { type: 'empty' },
        { type: 'empty' },
        { type: 'empty' },
        { type: 'empty' }
    ],
    droppedItems: [],         // ワールドに落ちているアイテムのリスト
};

// ============================================================
// ドロップアイテムシステム
// ブロックを壊したときにアイテムをワールドに落とす処理
// ============================================================

/**
 * 指定座標にアイテムをドロップする
 * @param {number} x, y, z - ドロップ位置
 * @param {string|number} itemId - アイテム種類 ('stick', 'stone' など) またはブロックイド
 */
function spawnDroppedItem(x, y, z, itemId) {
    const count = Math.floor(Math.random() * 2) + 1; // 1〜2個をランダムにドロップ
    for (let i = 0; i < count; i++) {
        // アイテム種類を判定: 整数ならブロックイド、文字列ならアイテムID
        const isBlockItem = typeof itemId === 'number' && PLACEABLE_BLOCKS.includes(itemId);
        const halfHeight = itemId === 'stick' ? 0.225 : 0.1;

        const item = {
            ...(isBlockItem ? { blockId: itemId, type: 'block' } : { itemId, type: 'item' }),
            x: x + 0.5, y: y + 0.5, z: z + 0.5,
            vx: (Math.random() - 0.5) * 0.05, // ランダムな水平飛び散り速度
            vy: 0.2,                            // 初期上方向速度
            vz: (Math.random() - 0.5) * 0.05,
            mesh: null,
            halfHeight,
            life: 600.0 // 600フレーム後（約10分）に消滅
        };

        // アイテムの3Dメッシュ: 棒は細長く、それ以外は小さな正方形
        const geo = itemId === 'stick'
            ? new THREE.BoxGeometry(0.1, 0.45, 0.1)
            : new THREE.BoxGeometry(0.2, 0.2, 0.2);

        // テクスチャアトラスのUVを手動でアイテムに対応したタイルに合わせる
        const uv = geo.attributes.uv;
        let uStart = 0, vStart = 0;
        if (itemId === 'stone' || itemId === 3) { uStart = 0.75; vStart = 0; }  // 石: 行0・列3
        else if (itemId === 'stick') { uStart = 0.25; vStart = 0.5; } // 棒: 行2・列1
        else { uStart = 0.5; vStart = 0; }  // 土: 行0・列2

        for (let j = 0; j < uv.count; j++) {
            uv.setXY(j, uStart + uv.getX(j) / 4, vStart + uv.getY(j) / 4);
        }

        const mesh = new THREE.Mesh(geo, worldMaterial);
        // 棒は斜め45度に傾けて見た目を自然にする
        if (itemId === 'stick') {
            mesh.rotation.z = Math.PI / 4;
            mesh.rotation.x = Math.PI / 8;
        }
        mesh.position.set(item.x, item.y, item.z);
        scene.add(mesh);
        item.mesh = mesh;
        gameState.droppedItems.push(item);
    }
}

/**
 * 毎フレーム呼ばれるドロップアイテムの更新処理
 * 重力・地面衝突・回収判定・消滅タイマーを処理する
 * @param {number} deltaTime - 前フレームからの経過時間（秒）
 */
function updateDroppedItems(deltaTime) {
    const p = gameState.player;
    // 後ろから走査して安全にspliceできるようにする
    for (let i = gameState.droppedItems.length - 1; i >= 0; i--) {
        const item = gameState.droppedItems[i];

        // 重力を適用（通常より3倍強め）
        item.vy -= 0.04;
        item.x += item.vx;
        item.y += item.vy;
        item.z += item.vz;

        // ボクセル地形との衝突: めり込んだら地面の上に乗せる
        if (getBlock(Math.floor(item.x), Math.floor(item.y), Math.floor(item.z)) !== 0) {
            item.y = Math.floor(item.y) + 1.0 + item.halfHeight;
            item.vy = 0;
            item.vx *= 0.8; // 水平方向に摩擦をかける
            item.vz *= 0.8;
        }

        if (item.mesh) {
            // 着地中は正弦波で上下に浮遊させ、常にY軸回転で目立たせる
            item.mesh.position.set(
                item.x,
                item.y + (item.vy === 0 ? Math.sin(performance.now() * 0.005) * 0.03 : 0),
                item.z
            );
            item.mesh.rotation.y += 0.03; // ゆっくり回転
        }

        // プレイヤーとの距離が1.5以内なら自動回収
        const dx = item.x - p.x;
        const dy = item.y - (p.y - 0.5);
        const dz = item.z - p.z;
        const dist = Math.sqrt(dx * dx + dy * dy + dz * dz);

        if (dist < 1.5) {
            // ブロックアイテムか通常アイテムかで判定
            const itemToCollect = item.type === 'block' ? item.blockId : item.itemId;

            if (collectItem(itemToCollect)) {
                scene.remove(item.mesh);
                gameState.droppedItems.splice(i, 1);
                updateHotbarUI();
                updateHeldItemMesh();
                continue;
            }
        }

        // 寿命を減らし、0以下になったら消滅
        item.life -= deltaTime;
        if (item.life <= 0) {
            scene.remove(item.mesh);
            gameState.droppedItems.splice(i, 1);
        }
    }
}

/**
 * インベントリにアイテムを追加する（スタックまたは空スロットに挿入）
 * @param {string|number} itemId - 追加するアイテムID（文字列）またはブロックID（整数）
 * @returns {boolean} 追加に成功したか
 */
function collectItem(itemId) {
    // itemIdがブロックIDか、アイテムIDか判定
    const isBlockItem = typeof itemId === 'number' && PLACEABLE_BLOCKS.includes(itemId);

    if (isBlockItem) {
        // ブロックアイテムの場合
        const blockId = itemId;

        // 同じブロックがすでにあればスタックする（スロット2〜7対象）
        for (let i = 2; i < 8; i++) {
            if (gameState.inventory[i].type === 'block' && gameState.inventory[i].blockId === blockId) {
                gameState.inventory[i].count++;
                return true;
            }
        }

        // 空きスロットに新規追加
        for (let i = 2; i < 8; i++) {
            if (gameState.inventory[i].type === 'empty') {
                gameState.inventory[i] = { type: 'block', blockId, count: 1 };
                return true;
            }
        }
    } else {
        // 通常アイテムの場合
        // 同じアイテムがすでにあればスタックする（スロット2〜7対象）
        for (let i = 2; i < 8; i++) {
            if (gameState.inventory[i].type === 'item' && gameState.inventory[i].itemId === itemId) {
                gameState.inventory[i].count++;
                return true;
            }
        }

        // 空きスロットに新規追加
        for (let i = 2; i < 8; i++) {
            if (gameState.inventory[i].type === 'empty') {
                gameState.inventory[i] = { type: 'item', itemId, count: 1 };
                return true;
            }
        }
    }

    return false; // インベントリが満杯
}

// ============================================================
// 手に持つアイテムの3D表示
// カメラにアタッチしたグループに選択中アイテムのメッシュを表示する
// ============================================================

// カメラの子として持ち物コンテナを追加（画面右下に見えるよう位置調整）
const heldItemContainer = new THREE.Group();
camera.add(heldItemContainer);
scene.add(camera);
heldItemContainer.position.set(0.35, -0.3, -0.5);

let currentHeldMesh = null; // 現在表示中のメッシュ参照

/**
 * 選択中スロットのアイテムに合わせて手元メッシュを切り替える
 */
function updateHeldItemMesh() {
    if (currentHeldMesh) heldItemContainer.remove(currentHeldMesh);
    currentHeldMesh = null;

    const item = gameState.inventory[gameState.selectedSlot];
    if (!item || item.type === 'empty') return;

    if (item.type === 'block') {
        // ブロックアイテム: テクスチャアトラスのタイルを貼った小さな立方体
        const geo = new THREE.BoxGeometry(0.25, 0.25, 0.25);
        // ブロックIDごとにアトラス内のタイル列・行を指定
        const atlasUV = {
            1: { tx: 0, ty: 0 }, // 草（側面）
            2: { tx: 2, ty: 0 }, // 土
            3: { tx: 3, ty: 0 }, // 石
            5: { tx: 1, ty: 1 }, // 木（側面）
            6: { tx: 2, ty: 1 }, // 葉
            7: { tx: 3, ty: 1 }, // 白壁
        };
        const tile = atlasUV[item.blockId] || { tx: 0, ty: 0 };
        const uStart = tile.tx * 0.25;
        const vStart = tile.ty * 0.25;
        const uv = geo.attributes.uv;
        for (let i = 0; i < uv.count; i++) {
            uv.setXY(i, uStart + uv.getX(i) * 0.25, vStart + uv.getY(i) * 0.25);
        }
        uv.needsUpdate = true;
        const m = new THREE.Mesh(geo, worldMaterial);
        m.rotation.set(0.4, -0.4, 0); // 少し傾けてブロックらしく見せる
        heldItemContainer.add(m);
        currentHeldMesh = m;
        gameState.player.selectedBlock = item.blockId;

    } else if (item.type === 'item') {
        let geo, mat;
        if (item.itemId === 'stick') {
            // 棒: 細い茶色の直方体を斜めに
            geo = new THREE.BoxGeometry(0.04, 0.5, 0.04);
            mat = new THREE.MeshStandardMaterial({ color: 0x8b4513 });
        } else if (item.itemId === 'stone') {
            // 石: アトラスから石テクスチャを貼った立方体（tx=3, ty=0）
            geo = new THREE.BoxGeometry(0.25, 0.25, 0.25);
            const stoneUV = geo.attributes.uv;
            for (let i = 0; i < stoneUV.count; i++) {
                stoneUV.setXY(i, 0.75 + stoneUV.getX(i) * 0.25, 0.0 + stoneUV.getY(i) * 0.25);
            }
            stoneUV.needsUpdate = true;
            mat = worldMaterial;
        }
        if (geo) {
            const m = new THREE.Mesh(geo, mat);
            if (item.itemId === 'stick') m.rotation.z = Math.PI / 4;
            heldItemContainer.add(m);
            currentHeldMesh = m;
        }

    } else if (item.type === 'bow') {
        // 弓: 3つのパーツ（本体＋上下の弓なり部分）を合わせたグループ
        const group = new THREE.Group();
        const mainMat = new THREE.MeshStandardMaterial({ color: 0x8b4513 });
        const bowMesh = new THREE.Mesh(new THREE.BoxGeometry(0.04, 0.5, 0.04), mainMat);
        const top = new THREE.Mesh(new THREE.BoxGeometry(0.04, 0.15, 0.04), mainMat);
        top.position.set(0.05, 0.25, 0);
        top.rotation.z = -0.4;
        const bot = new THREE.Mesh(new THREE.BoxGeometry(0.04, 0.15, 0.04), mainMat);
        bot.position.set(0.05, -0.25, 0);
        bot.rotation.z = 0.4;
        group.add(bowMesh, top, bot);
        currentHeldMesh = group;
        currentHeldMesh.rotation.set(0.2, -0.8, 0);

    } else if (item.type === 'arrow') {
        // 矢: 棒状の軸＋円錐形の矢じりを合わせたグループ
        const group = new THREE.Group();
        const shaft = new THREE.Mesh(
            new THREE.BoxGeometry(0.02, 0.02, 0.5),
            new THREE.MeshStandardMaterial({ color: 0x8b4513 })
        );
        const head = new THREE.Mesh(
            new THREE.ConeGeometry(0.03, 0.08, 4),
            new THREE.MeshStandardMaterial({ color: 0x777777 })
        );
        head.rotation.x = Math.PI / 2;
        head.position.z = -0.25;
        group.add(shaft, head);
        currentHeldMesh = group;
        currentHeldMesh.rotation.set(0.5, -0.3, 0);
    }

    if (currentHeldMesh) heldItemContainer.add(currentHeldMesh);
}
updateHeldItemMesh();

// ============================================================
// ホットバーUI
// 画面下部のスロット表示を現在のインベントリ状態に同期する
// ============================================================

/**
 * ホットバーの全スロットの表示（アイコン・数字・選択枠）を更新する
 */
function updateHotbarUI() {
    const slots = document.querySelectorAll('.slot');
    const atlas = window.textureAtlasCanvas;
    const atlasURL = atlas ? atlas.toDataURL() : '';

    slots.forEach((slot) => {
        const idx = parseInt(slot.dataset.index);
        const item = gameState.inventory[idx];

        // 選択中スロットに白枠を付ける
        slot.classList.toggle('selected', idx === gameState.selectedSlot);

        const iconSpan = slot.querySelector('.icon');
        const countSpan = slot.querySelector('.count');

        if (item && item.type !== 'empty') {
            let displayId;
            if (item.type === 'item') {
                displayId = item.itemId;
            } else if (item.type === 'block') {
                displayId = item.blockId;
            } else {
                displayId = item.type;
            }

            if (iconSpan) {
                iconSpan.innerText = '';
                iconSpan.style.backgroundImage = '';
                iconSpan.style.backgroundSize = '';
                iconSpan.style.backgroundPosition = '';

                if (displayId === 'stone' || displayId === 'stick' || typeof displayId === 'number') {
                    // 石・棒・ブロックはテクスチャアトラスの該当タイルをCSSで切り抜いて表示
                    iconSpan.style.backgroundImage = `url(${atlasURL})`;
                    iconSpan.style.backgroundSize = '400% 400%';
                    iconSpan.style.width = '40px';
                    iconSpan.style.height = '40px';
                    iconSpan.style.display = 'block';

                    let col = 0, row = 0;
                    if (displayId === 'stone') { col = 3; row = 0; }
                    else if (displayId === 'stick') { col = 1; row = 2; }
                    else if (typeof displayId === 'number') {
                        // ブロックイドから列・行を計算
                        const atlasUV = { 1: { tx: 0, ty: 0 }, 2: { tx: 2, ty: 0 }, 3: { tx: 3, ty: 0 }, 5: { tx: 1, ty: 1 }, 6: { tx: 2, ty: 1 }, 7: { tx: 3, ty: 1 } };
                        const tile = atlasUV[displayId] || { tx: 0, ty: 0 };
                        col = tile.tx;
                        row = tile.ty;
                    }
                    iconSpan.style.backgroundPosition = `${(col / 3) * 100}% ${(row / 3) * 100}%`;
                } else {
                    // 弓・矢は絵文字で表示
                    const icons = { bow: '🏹', arrow: '⤅' };
                    iconSpan.innerText = icons[displayId] || '❓';
                }
            }

            if (countSpan) {
                // 弓は耐久値・矢は残弾数・それ以外はスタック数を表示
                countSpan.innerText = displayId === 'bow' ? gameState.bowDurability
                    : displayId === 'arrow' ? gameState.ammo
                        : item.count;
            } else if (item.count > 1 || item.type === 'item' || item.type === 'block') {
                const span = document.createElement('span');
                span.className = 'count';
                span.innerText = item.count;
                slot.appendChild(span);
            }
        } else {
            if (iconSpan) {
                iconSpan.innerText = '';
                iconSpan.style.backgroundImage = '';
                iconSpan.style.backgroundSize = '';
                iconSpan.style.backgroundPosition = '';
                iconSpan.style.width = '';
                iconSpan.style.height = '';
                iconSpan.style.display = '';
            }
            if (countSpan) countSpan.innerText = '';
        }
    });
}

// ============================================================
// マルチプレイヤー（Socket.IO）セットアップ
// サーバーとのリアルタイム通信を管理する
// ============================================================

// socket.ioが読み込まれていない環境（ローカルテスト）ではダミーオブジェクトで代替
const socket = (typeof io !== 'undefined')
    ? io()
    : { connected: false, on: () => { }, emit: () => { } };

// 他のプレイヤーの3Dメッシュを管理するオブジェクトとグループ
const otherPlayers = {};
const otherPlayerGroup = new THREE.Group();
scene.add(otherPlayerGroup);

/**
 * 新しい他プレイヤーのメッシュを作成してシーンに追加する
 * @param {string} id         - プレイヤーのソケットID
 * @param {object} playerInfo - 初期位置情報 { x, y, z }
 */
function addOtherPlayer(id, playerInfo) {
    const mat = new THREE.MeshStandardMaterial({ color: Math.random() * 0xffffff }); // ランダムカラー
    const geo = new THREE.BoxGeometry(0.8, 1.8, 0.8); // 人型の大きさに近い直方体
    const mesh = new THREE.Mesh(geo, mat);
    mesh.position.set(playerInfo.x, playerInfo.y, playerInfo.z);
    otherPlayerGroup.add(mesh);
    otherPlayers[id] = { mesh };
}

// 接続時: サーバーから既存プレイヤー全員の情報を受け取り追加する
socket.on('currentPlayers', (players) => {
    Object.keys(players).forEach((id) => {
        if (id === socket.id) return; // 自分自身はスキップ
        addOtherPlayer(id, players[id]);
    });
});

// 新規プレイヤーが参加してきたときにメッシュを追加する
socket.on('newPlayer', (data) => {
    addOtherPlayer(data.id, data.player);
});

// プレイヤーが切断したときにメッシュを削除する
socket.on('playerDisconnected', (id) => {
    if (otherPlayers[id]) {
        otherPlayerGroup.remove(otherPlayers[id].mesh);
        delete otherPlayers[id];
    }
});

// 他プレイヤーが移動したとき、そのメッシュの位置と向きを更新する
socket.on('playerMoved', (data) => {
    if (otherPlayers[data.id]) {
        otherPlayers[data.id].mesh.position.set(data.player.x, data.player.y, data.player.z);
        otherPlayers[data.id].mesh.rotation.y = data.player.yaw;
    }
});

// 他プレイヤーがブロックを壊したとき、こちらの世界にも反映する
socket.on('blockBroken', (data) => {
    setBlock(data.x, data.y, data.z, 0, false); // sync=falseで再送信を防ぐ
});

// 他プレイヤーがブロックを置いたとき、こちらの世界にも反映する
socket.on('blockSet', (data) => {
    setBlock(data.x, data.y, data.z, data.type, false);
});

// 他プレイヤーが矢を放ったとき、その矢をこちらの世界でも飛ばす
socket.on('arrowShot', (data) => {
    gameState.arrows.push({
        x: data.arrow.x, y: data.arrow.y, z: data.arrow.z,
        vx: data.arrow.vx, vy: data.arrow.vy, vz: data.arrow.vz,
        yaw: data.arrow.yaw, pitch: data.arrow.pitch,
        damage: data.arrow.damage,
        hit: false, life: 30.0, ownerId: data.id
    });
});

// サーバーからダメージを受けたとき、自分のHPを減らす
socket.on('takeDamage', (data) => {
    gameState.player.health -= data.damage;
});

// 敵がダメージを受けたとき（他プレイヤーの射撃も含む）、対象敵のHPを減らす
socket.on('enemyDamaged', (data) => {
    const enemy = gameState.enemies.find(e => e.id === data.enemyId);
    if (enemy) {
        enemy.health -= data.damage;
        if (enemy.health <= 0) {
            gameState.enemies = gameState.enemies.filter(e => e.id !== data.enemyId);
        }
    }
});

// ============================================================
// 入力ハンドリング
// キー・マウス・スクロールの入力をゲーム状態に反映する
// ============================================================

document.addEventListener('keydown', (e) => {
    gameState.keys[e.code] = true;
    // Shiftキーでダッシュ開始（解除は前進キーを離したとき）
    if (e.code === 'ShiftLeft' || e.code === 'ShiftRight') {
        gameState.player.isDashing = true;
    }
});

document.addEventListener('keyup', (e) => {
    gameState.keys[e.code] = false;
});

// スロット選択・インベントリ開閉のキー処理
document.addEventListener('keydown', (e) => {
    // 1〜8キーでホットバースロットを直接選択（インベントリ中は無効）
    if (e.key >= '1' && e.key <= '8') {
        gameState.selectedSlot = parseInt(e.key) - 1;
        updateHotbarUI();
        updateHeldItemMesh();
    }
});

// マウスホイールでスロットを循環選択（8→0→1...）
document.addEventListener('wheel', (e) => {
    if (document.pointerLockElement === canvas) {
        if (e.deltaY > 0) gameState.selectedSlot = (gameState.selectedSlot + 1) % 8;
        else gameState.selectedSlot = (gameState.selectedSlot - 1 + 8) % 8;
        updateHotbarUI();
        updateHeldItemMesh();
    }
}, { passive: true });

// ============================================================
// ポインターロック（マウスカーソル制御）
// ゲーム開始時にマウスをキャンバスに拘束して視点操作を可能にする
// ============================================================

const titleScreen = document.getElementById('title-screen');
const hud = document.getElementById('hud');

// タイトル画面クリックでポインターロックを要求しゲームを開始
titleScreen.addEventListener('click', () => {
    // ゲームオーバー状態からのリスタートはHPとポジションをリセット
    if (gameState.player.health <= 0) {
        gameState.player.health = 100;
        gameState.player.x = 0;
        gameState.player.y = 15;
        gameState.player.z = 0;
        gameState.player.velocity.y = 0;
        gameState.bowDurability = 20;
    }
    canvas.oncontextmenu = (e) => e.preventDefault(); // 右クリックメニューを無効化
    canvas.requestPointerLock();
});

// ポインターロックの状態変化に合わせてHUD・ゲームループの表示を切り替える
document.addEventListener('pointerlockchange', () => {
    const crosshair = document.getElementById('crosshair');
    if (document.pointerLockElement === canvas) {
        // ロック獲得: ゲームUIを表示してループ開始
        titleScreen.classList.remove('active');
        hud.style.display = 'block';
        if (crosshair) crosshair.style.display = 'block';
        if (!gameState.isRunning) {
            gameState.isRunning = true;
            gameState.lastTime = performance.now();
            requestAnimationFrame(gameLoop);
        }
    } else {
        // 通常のESC: HPが残っていればタイトルへ戻る
        if (gameState.player.health > 0) {
            titleScreen.classList.add('active');
        }
        hud.style.display = 'none';
        if (crosshair) crosshair.style.display = 'none';
        gameState.isRunning = false;

    }
});

// ゲームオーバー画面クリックでタイトルへ戻る
document.getElementById('game-over-screen').addEventListener('click', () => {
    gameState.player.health = 100;
    gameState.player.x = 0;
    gameState.player.y = 15;
    gameState.player.z = 0;
    gameState.player.velocity.y = 0;
    document.getElementById('game-over-screen').classList.remove('active');
    titleScreen.classList.add('active');
});

// ============================================================
// レイキャスト
// カメラの向きに沿ってブロックとの交差を調べる
// ============================================================

/**
 * レイキャスト: 指定方向に光線を飛ばしてヒットしたブロックを返す
 * @param {object} origin - 始点座標 { x, y, z }
 * @param {object} dir    - 方向ベクトル（正規化済み）
 * @param {number} maxDist - 最大検索距離
 * @returns {{ hit, x, y, z, norm }} ヒット情報と法線方向
 */
function raycast(origin, dir, maxDist) {
    let t = 0.0;
    const step = 0.05; // 細かいステップで精度を上げる
    let lastMapX = -1, lastMapY = -1, lastMapZ = -1;
    let hitMapX = -1, hitMapY = -1, hitMapZ = -1;
    let hit = false;
    let norm = [0, 0, 0];

    while (t < maxDist) {
        const cx = origin.x + dir.x * t;
        const cy = origin.y + dir.y * t;
        const cz = origin.z + dir.z * t;

        const mx = Math.floor(cx);
        const my = Math.floor(cy);
        const mz = Math.floor(cz);

        if (getBlock(mx, my, mz) !== 0) {
            hitMapX = mx; hitMapY = my; hitMapZ = mz;
            hit = true;
            // 直前の空気ブロック位置から法線（面の方向）を計算する
            norm = lastMapX !== -1
                ? [lastMapX - mx, lastMapY - my, lastMapZ - mz]
                : [0, 1, 0]; // フォールバック: 上向き
            break;
        }

        lastMapX = mx; lastMapY = my; lastMapZ = mz;
        t += step;
    }

    return { hit, x: hitMapX, y: hitMapY, z: hitMapZ, norm };
}

// ============================================================
// ブロック設置機能
// ============================================================

/**
 * ブロック設置関数
 * 指定位置にブロックを配置する際の全ロジックを担当
 * 
 * @param {number} targetX - ターゲットブロックのX座標
 * @param {number} targetY - ターゲットブロックのY座標
 * @param {number} targetZ - ターゲットブロックのZ座標
 * @param {array} normal - ターゲットブロック表面の法線ベクトル [nx, ny, nz]
 * @param {number} blockId - 設置するブロックのID
 * @returns {boolean} 設置に成功したか
 */
function placeBlock(targetX, targetY, targetZ, normal, blockId) {
    // 1. 法線方向にオフセットして配置位置を計算
    const placeX = targetX + normal[0];
    const placeY = targetY + normal[1];
    const placeZ = targetZ + normal[2];

    // 2. プレイヤーとの詳突判定
    // プレイヤーの体の大きさ: 幅 0.8×0.8、高さ 1.5
    const playerX = gameState.player.x;
    const playerY = gameState.player.y;
    const playerZ = gameState.player.z;

    // ブロック中心座標
    const blockCenterX = placeX + 0.5;
    const blockCenterY = placeY + 0.5;
    const blockCenterZ = placeZ + 0.5;

    // プレイヤーとブロックの距離を計算
    const dx = Math.abs(blockCenterX - playerX);
    const dy = Math.abs(blockCenterY - playerY);
    const dz = Math.abs(blockCenterZ - playerZ);

    // プレイヤーの当たり判定ボックスとの詳突チェック
    // プレイヤーの幅: 0.8（±0.4）、高さ: 1.5（下から 1.55まで）
    const playerHalfWidth = 0.4;
    const playerHeight = 1.5;

    if (dx <= playerHalfWidth + 0.5 &&
        dz <= playerHalfWidth + 0.5 &&
        dy <= playerHeight / 2 + 0.5) {
        // プレイヤーと重なっている
        return false;
    }

    // 3. 既存ブロックとの重複チェック
    // 配置位置にすでにブロックがあれば設置できない
    if (getBlock(placeX, placeY, placeZ) !== 0) {
        return false;
    }

    // 4. ブロックを設置
    setBlock(placeX, placeY, placeZ, blockId);

    return true;
}

/**
 * ブロック設置が可能かどうかを判定する
 * 
 * @returns {boolean} 設置可能な状態か
 */
function canPlaceBlock() {
    const currentItem = gameState.inventory[gameState.selectedSlot];

    // 現在選択中のアイテムがブロックカテゴリか確認
    if (!currentItem || currentItem.type !== 'block') {
        return false;
    }

    // ブロックの数が 1 以上あるか確認
    if (!currentItem.count || currentItem.count <= 0) {
        return false;
    }

    // カーソルが向いているブロックがあるか確認
    if (!gameState.targetBlock || !gameState.targetBlock.hit) {
        return false;
    }

    // blockIdが設置可能なブロックか確認
    if (!PLACEABLE_BLOCKS.includes(currentItem.blockId)) {
        return false;
    }

    return true;
}

/**
 * ブロック設置を実行する
 * canPlaceBlock()で事前チェック後に呼び出す
 */
function executeBlockPlacement() {
    console.log('executeBlockPlacement called');
    console.log('canPlaceBlock result:', canPlaceBlock());
    console.log('targetBlock:', gameState.targetBlock);

    if (!canPlaceBlock()) {
        console.log('canPlaceBlock returned false');
        return false;
    }

    const currentItem = gameState.inventory[gameState.selectedSlot];
    const { x, y, z, norm } = gameState.targetBlock;

    // ブロック設置を試みる
    const success = placeBlock(x, y, z, norm, currentItem.blockId);

    if (success) {
        // 設置成功時、インベントリのブロック数を 1 減らす
        currentItem.count--;

        // countが 0 になったらスロットを空にする
        if (currentItem.count <= 0) {
            gameState.inventory[gameState.selectedSlot] = { type: 'empty' };
        }

        // UI更新
        updateHotbarUI();
        updateHeldItemMesh();

        return true;
    }

    return false;
}

// ============================================================
// マウスボタン操作
// 左クリック: 採掘 / 右クリック: 弓チャージまたはブロック設置
// ============================================================

document.addEventListener('mousedown', (e) => {
    if (document.pointerLockElement !== canvas) return;

    const currentItem = gameState.inventory[gameState.selectedSlot];
    if (e.button === 2) {
        // 右クリック: 弓を持っていればチャージ開始、ブロックを持っていれば設置
        if (currentItem?.type === 'bow') {
            gameState.isCharging = true;
            gameState.charge = 0;
        } else if (currentItem?.type === 'block') {
            // ブロック設置処理を実行
            executeBlockPlacement();
        }
    } else if (e.button === 0) {
        // 左クリック: 採掘フラグをセット、葉は即時破壊
        gameState.isMouseDown0 = true;
        if (gameState.targetBlock?.hit) {
            const { x, y, z } = gameState.targetBlock;
            if (getBlock(x, y, z) === 6) setBlock(x, y, z, 0); // 葉: 即時破壊
        }
    }
});

document.addEventListener('mouseup', (e) => {
    if (document.pointerLockElement !== canvas) return;

    if (e.button === 2 && gameState.isCharging) {
        // 右クリック離し: 溜めた弓を発射
        shootArrow();
        gameState.isCharging = false;
        gameState.charge = 0;
    } else if (e.button === 0) {
        gameState.isMouseDown0 = false;
    }
});

// マウス移動: 感度0.002でプレイヤーの視点（ヨー・ピッチ）を更新
document.addEventListener('mousemove', (e) => {
    if (document.pointerLockElement !== canvas) return;

    const sensitivity = 0.002;
    gameState.player.yaw -= e.movementX * sensitivity;
    gameState.player.pitch -= e.movementY * sensitivity;

    // ピッチを±90度以内に制限して画面が反転しないようにする
    const maxPitch = Math.PI / 2 - 0.01;
    gameState.player.pitch = Math.max(-maxPitch, Math.min(maxPitch, gameState.player.pitch));
});

// ウィンドウサイズ変更時にカメラとレンダラーを再設定
function resizeCanvas() {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
}
window.addEventListener('resize', resizeCanvas);
resizeCanvas();

// ============================================================
// テクスチャアトラス生成
// 4×4グリッドの256×256px Canvasに全ブロックのテクスチャを描画し
// Three.jsのテクスチャとして使用する
// ============================================================

function createTextureAtlas() {
    const tCanvas = document.createElement('canvas');
    tCanvas.width = 256;  // 64px × 4列
    tCanvas.height = 256; // 64px × 4行
    const ctx = tCanvas.getContext('2d');
    ctx.clearRect(0, 0, 256, 256);

    // --- 各ブロックテクスチャ描画関数 ---

    // 土ブロック: 茶色の地色にランダムな斑点
    function drawDirt(x, y) {
        ctx.fillStyle = '#654321';
        ctx.fillRect(x, y, 64, 64);
        ctx.fillStyle = '#543210';
        for (let i = 0; i < 40; i++) {
            ctx.fillRect(x + Math.random() * 60, y + Math.random() * 60, 4, 4);
        }
    }

    // 草ブロック（上面）: 緑の地色にランダムな斑点
    function drawGrassTop(x, y) {
        ctx.fillStyle = '#5bb349';
        ctx.fillRect(x, y, 64, 64);
        ctx.fillStyle = '#4aa238';
        for (let i = 0; i < 40; i++) {
            ctx.fillRect(x + Math.random() * 60, y + Math.random() * 60, 4, 4);
        }
    }

    // 草ブロック（側面）: 下が土、上部に緑の縁を描画
    function drawGrassSide(x, y) {
        drawDirt(x, y); // ベースに土を描く
        ctx.fillStyle = '#5bb349';
        ctx.beginPath();
        ctx.moveTo(x, y); ctx.lineTo(x + 64, y); ctx.lineTo(x + 64, y + 16);
        // ランダムなギザギザで草らしいエッジを作る
        for (let px = 64; px >= 0; px -= 8) {
            ctx.lineTo(x + px, y + 16 + Math.random() * 8);
        }
        ctx.fill();
    }

    // 石ブロック: レンガパターンに立体感を付けた石積み模様
    function drawStone(x, y) {
        ctx.save();
        ctx.beginPath();
        ctx.rect(x, y, 64, 64);
        ctx.clip(); // 描画範囲を64×64に制限（シームレスタイリング用）

        ctx.fillStyle = '#6e6e6e';
        ctx.fillRect(x, y, 64, 64);

        // 4行×5列の石ブロックパターン（奇数行はオフセット）
        for (let py = 0; py < 4; py++) {
            for (let px = -1; px < 4; px++) {
                const offX = (py % 2 === 0) ? 0 : 8;
                const sx = x + offX + px * 16 + 1;
                const sy = y + py * 16 + 1;
                const shade = 120 + Math.floor(Math.random() * 35);

                const drawPebble = (bx, by) => {
                    ctx.fillStyle = `rgb(${shade},${shade},${shade})`;
                    ctx.fillRect(bx, by, 14, 14);
                    // 上・左に明るい縁（ハイライト）
                    ctx.fillStyle = `rgb(${shade + 30},${shade + 30},${shade + 30})`;
                    ctx.fillRect(bx, by, 14, 2);
                    ctx.fillRect(bx, by, 2, 14);
                    // 下・右に暗い縁（シャドウ）
                    ctx.fillStyle = `rgb(${shade - 30},${shade - 30},${shade - 30})`;
                    ctx.fillRect(bx, by + 12, 14, 2);
                    ctx.fillRect(bx + 12, by, 2, 14);
                };
                drawPebble(sx, sy);
                drawPebble(sx + 64, sy); // シームレスタイリング用に左右に複製
                drawPebble(sx - 64, sy);
            }
        }
        ctx.restore();
    }

    // ひびの入った石: 石の上にひび割れ線を追加
    function drawCrackedStone(x, y) {
        drawStone(x, y);
        ctx.strokeStyle = '#555';
        ctx.lineWidth = 2;
        ctx.beginPath();
        ctx.moveTo(x + 10, y + 10); ctx.lineTo(x + 30, y + 40); ctx.lineTo(x + 10, y + 50);
        ctx.moveTo(x + 50, y + 10); ctx.lineTo(x + 40, y + 30); ctx.lineTo(x + 55, y + 55);
        ctx.stroke();
    }

    // 木ブロック（側面）: マインクラフト風のランダムなジグザグ縦縞
    function drawWood(x, y) {
        const darks = ['#2D2213', '#3a2c1a'];
        const lights = ['#745A35', '#624a2d'];
        ctx.fillStyle = '#513d26';
        ctx.fillRect(x, y, 64, 64);

        const pixelSize = 4;
        // 10本のジグザグ縦縞を描く（暗い縞・明るい縞をランダムに混在）
        for (let i = 0; i < 10; i++) {
            let curX = Math.floor(Math.random() * 16);
            const isDark = Math.random() < 0.6;
            const colorSet = isDark ? darks : lights;

            for (let py = 0; py < 16; py++) {
                if (Math.random() < 0.35) {
                    curX = (curX + (Math.random() < 0.5 ? -1 : 1) + 16) % 16; // 横にドリフト
                }
                ctx.fillStyle = colorSet[Math.floor(Math.random() * colorSet.length)];
                ctx.fillRect(x + curX * pixelSize, y + py * pixelSize, pixelSize, pixelSize);
                if (Math.random() < 0.4) {
                    // 横に隣接するピクセルも塗って縞を太くする
                    ctx.fillRect(x + ((curX + 1) % 16) * pixelSize, y + py * pixelSize, pixelSize, pixelSize);
                }
            }
        }
        // 細かいランダムな縦縞を追加でディテールを増やす
        for (let i = 0; i < 15; i++) {
            const rx = Math.floor(Math.random() * 16);
            const ry = Math.floor(Math.random() * 12);
            ctx.fillStyle = (Math.random() < 0.5) ? darks[0] : lights[0];
            ctx.fillRect(x + rx * pixelSize, y + ry * pixelSize, pixelSize, pixelSize * 3);
        }
    }

    // 木ブロック（上面）: 年輪のような同心四角形パターン
    function drawWoodTop(x, y) {
        ctx.clearRect(x, y, 64, 64);
        ctx.fillStyle = '#3b291d'; ctx.fillRect(x, y, 64, 64);      // 外皮（暗）
        ctx.fillStyle = '#bd9b71'; ctx.fillRect(x + 4, y + 4, 56, 56);  // 年輪1（明）
        ctx.fillStyle = '#a48259'; ctx.fillRect(x + 12, y + 12, 40, 40); // 年輪2（暗）
        ctx.fillStyle = '#bd9b71'; ctx.fillRect(x + 20, y + 20, 24, 24); // 年輪3（明）
        ctx.fillStyle = '#a48259'; ctx.fillRect(x + 28, y + 28, 8, 8);   // 中心（暗）
    }

    // 葉ブロック: 複数の緑色をランダムに配置した透過テクスチャ（約70%覆い）
    function drawLeaves(x, y) {
        ctx.clearRect(x, y, 64, 64);
        const colors = ['#1b5e20', '#2e7d32', '#388e3c', '#43a047'];
        const pixelSize = 4;
        for (let py = 0; py < 16; py++) {
            for (let px = 0; px < 16; px++) {
                if (Math.random() < 0.7) { // 70%の確率でピクセルを塗る（30%は透明）
                    ctx.fillStyle = colors[Math.floor(Math.random() * colors.length)];
                    ctx.fillRect(x + px * pixelSize, y + py * pixelSize, pixelSize, pixelSize);
                }
            }
        }
        // 葉脈のような暗い横線を追加
        ctx.fillStyle = '#1b5e20';
        for (let i = 0; i < 8; i++) {
            ctx.fillRect(
                x + Math.floor(Math.random() * 16) * pixelSize,
                y + Math.floor(Math.random() * 16) * pixelSize,
                pixelSize * 2, pixelSize / 2
            );
        }
    }

    // 白壁ブロック: オフホワイトのパネル線模様
    function drawWhiteWall(x, y) {
        ctx.fillStyle = '#f5f5f5';
        ctx.fillRect(x, y, 64, 64);
        ctx.strokeStyle = '#e0e0e0';
        ctx.lineWidth = 2;
        ctx.strokeRect(x + 2, y + 2, 60, 30);  // 上段パネル
        ctx.strokeRect(x + 2, y + 32, 60, 30); // 下段パネル
    }

    // 棒アイテム: 斜め45度の茶色い線
    function drawStick(x, y) {
        ctx.clearRect(x, y, 64, 64);
        ctx.strokeStyle = '#8b4513';
        ctx.lineWidth = 6;
        ctx.lineCap = 'round';
        ctx.beginPath();
        ctx.moveTo(x + 16, y + 48);
        ctx.lineTo(x + 48, y + 16);
        ctx.stroke();
        ctx.fillStyle = '#5d2e0d';
        ctx.fillRect(x + 24, y + 40, 4, 4); // 木目的な暗いスポット
        ctx.fillRect(x + 36, y + 28, 4, 4);
    }

    // --- アトラスのUVレイアウト ---
    // 行0: [列0]草側面, [列1]草上面, [列2]土,      [列3]石
    // 行1: [列0]ひび石, [列1]木側面,  [列2]葉,      [列3]白壁
    // 行2: [列0]木上面, [列1]棒
    drawGrassSide(0, 0);
    drawGrassTop(64, 0);
    drawDirt(128, 0);
    drawStone(192, 0);
    drawCrackedStone(0, 64);
    drawWood(64, 64);
    drawLeaves(128, 64);
    drawWhiteWall(192, 64);
    drawWoodTop(0, 128);
    drawStick(64, 128);

    const texture = new THREE.CanvasTexture(tCanvas);
    window.textureAtlasCanvas = tCanvas; // ホットバーUIからも参照できるようグローバルに公開
    texture.magFilter = THREE.NearestFilter;          // ピクセルアートらしいくっきりした拡大
    texture.minFilter = THREE.NearestMipmapLinearFilter; // 縮小時はミップマップで滑らかに
    texture.colorSpace = THREE.SRGBColorSpace;
    texture.flipY = false; // UVが上下反転しないようにする
    return texture;
}

// テクスチャアトラスを生成し、ワールド全体で共有するマテリアルを作成
const worldTexture = createTextureAtlas();
const worldMaterial = new THREE.MeshStandardMaterial({
    map: worldTexture,
    alphaTest: 0.5,        // 半透明部分を完全に透明にする（葉ブロック用）
    side: THREE.DoubleSide // 裏面も描画する（葉など薄いブロック用）
});

// ============================================================
// ボクセルワールドエンジン（チャンク方式）
// ワールドを16×32×16ブロックのチャンクに分割して管理する
// ============================================================

const CHUNK_SIZE = 16;   // チャンクの水平サイズ（XZ方向）
const CHUNK_HEIGHT = 32; // チャンクの垂直サイズ（Y方向）

/**
 * 一つのチャンクを表すクラス
 * ブロックデータをUint8Array（1バイト/ブロック）で保持する
 */
class Chunk {
    constructor(cx, cz) {
        this.cx = cx; // チャンクのX座標インデックス
        this.cz = cz; // チャンクのZ座標インデックス
        // 16 × 32 × 16 = 8192 バイトのブロックデータ
        this.data = new Uint8Array(CHUNK_SIZE * CHUNK_HEIGHT * CHUNK_SIZE);
        this.mesh = null;        // 生成されたThree.jsメッシュ（null=未生成）
        this.needsUpdate = true; // true のとき次フレームでメッシュを再構築する
    }

    /** チャンク内ローカル座標でブロック種類を取得（範囲外は0=空気）*/
    getBlockLocal(x, y, z) {
        if (x < 0 || y < 0 || z < 0 || x >= CHUNK_SIZE || y >= CHUNK_HEIGHT || z >= CHUNK_SIZE) return 0;
        return this.data[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE];
    }

    /** チャンク内ローカル座標でブロック種類を設定し、メッシュ再構築フラグを立てる */
    setBlockLocal(x, y, z, val) {
        if (x < 0 || y < 0 || z < 0 || x >= CHUNK_SIZE || y >= CHUNK_HEIGHT || z >= CHUNK_SIZE) return;
        this.data[x + z * CHUNK_SIZE + y * CHUNK_SIZE * CHUNK_SIZE] = val;
        this.needsUpdate = true;
    }
}

// チャンクのMapストア: キー "cx,cz" → Chunkインスタンス
const worldChunks = new Map();

function getChunkKey(cx, cz) { return `${cx},${cz}`; }
function getChunk(cx, cz) { return worldChunks.get(getChunkKey(cx, cz)); }

/**
 * ワールド座標でブロック種類を取得する（チャンクをまたいで動作する）
 * @returns {number} ブロックID（0=空気）
 */
function getBlock(x, y, z) {
    if (y < 0 || y >= CHUNK_HEIGHT) return 0;
    const cx = Math.floor(x / CHUNK_SIZE);
    const cz = Math.floor(z / CHUNK_SIZE);
    const chunk = getChunk(cx, cz);
    if (!chunk) return 0;
    // 負座標でも正しくローカル座標に変換する（剰余の符号対策）
    const lx = ((x % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
    const lz = ((z % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
    return chunk.getBlockLocal(lx, y, lz);
}

/**
 * ワールド座標でブロックを設置・破壊し、必要に応じてサーバーに同期する
 * @param {number} val  - 設置するブロックID（0=破壊）
 * @param {boolean} sync - trueのときsocket.ioで他プレイヤーに送信する
 */
function setBlock(x, y, z, val, sync = true) {
    if (y < 0 || y >= CHUNK_HEIGHT) return;
    const cx = Math.floor(x / CHUNK_SIZE);
    const cz = Math.floor(z / CHUNK_SIZE);
    const chunk = getChunk(cx, cz);
    if (!chunk) return;

    if (val === 0) {
        // ブロック破壊時: ブロック種類に応じたアイテムをドロップ
        const blockType = getBlock(x, y, z);
        if (blockType === 6) spawnDroppedItem(x, y, z, 'stick');          // 葉 → 棒
        else if (blockType === 3 || blockType === 4) spawnDroppedItem(x, y, z, blockType); // 石/ひび石 → ブロックアイテム
        else if (blockType === 5) spawnDroppedItem(x, y, z, 'stick');     // 木 → 棒

        if (socket.connected) socket.emit('breakBlock', { x, y, z });
    } else {
        if (sync && socket.connected) socket.emit('setBlock', { x, y, z, type: val });
    }

    const lx = ((x % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
    const lz = ((z % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
    chunk.setBlockLocal(lx, y, lz, val);

    // チャンク境界上のブロックを変更した場合は隣接チャンクも再構築する
    if (lx === 0) { const n = getChunk(cx - 1, cz); if (n) n.needsUpdate = true; }
    if (lx === CHUNK_SIZE - 1) { const n = getChunk(cx + 1, cz); if (n) n.needsUpdate = true; }
    if (lz === 0) { const n = getChunk(cx, cz - 1); if (n) n.needsUpdate = true; }
    if (lz === CHUNK_SIZE - 1) { const n = getChunk(cx, cz + 1); if (n) n.needsUpdate = true; }
}

/**
 * 指定チャンク座標にチャンクを生成してブロックデータを埋める
 * 地形・壁・木・石構造物を配置する
 */
function generateChunk(cx, cz) {
    const chunk = new Chunk(cx, cz);

    // 1. 基本地形生成
    // ワールドは64×64ブロックの部屋が3×3並んだ構造
    // 内壁: worldX = ±32, worldZ = ±32 / 外壁: worldX = ±96, worldZ = ±96
    for (let lz = 0; lz < CHUNK_SIZE; lz++) {
        for (let lx = 0; lx < CHUNK_SIZE; lx++) {
            const worldX = cx * CHUNK_SIZE + lx;
            const worldZ = cz * CHUNK_SIZE + lz;
            const h = 5; // 地面の高さ（Yレベル5）

            // 内壁・外壁の判定
            const isInnerWallX = (worldX === -32 || worldX === 32);
            const isInnerWallZ = (worldZ === -32 || worldZ === 32);
            const isOuterWallX = (worldX === -96 || worldX === 95);
            const isOuterWallZ = (worldZ === -96 || worldZ === 95);
            let isWall = isInnerWallX || isInnerWallZ || isOuterWallX || isOuterWallZ;

            // 内壁には3×3の通路（廊下）を開ける
            if (isWall && (isInnerWallX || isInnerWallZ) && !(isOuterWallX || isOuterWallZ)) {
                const otherCoord = isInnerWallX ? worldZ : worldX;
                const distanceToCenter = Math.abs(((otherCoord + 32) % 64 + 64) % 64 - 32);
                if (distanceToCenter <= 1) isWall = false;
            }

            for (let y = 0; y < CHUNK_HEIGHT; y++) {
                if (y === h) {
                    chunk.setBlockLocal(lx, y, lz, 1); // 最上層: 草
                } else if (y < h) {
                    // 地下: 浅い部分は土、深い部分は石
                    chunk.setBlockLocal(lx, y, lz, y < 3 ? 3 : 2);
                } else if (y > h && y <= h + 8) {
                    // 壁の部分: 外壁は常に白壁、内壁は通路を除いて白壁
                    if (isOuterWallX || isOuterWallZ) {
                        chunk.setBlockLocal(lx, y, lz, 7); // 外壁: 破壊不可の白壁
                    } else if (isInnerWallX || isInnerWallZ) {
                        const otherCoord = isInnerWallX ? worldZ : worldX;
                        const distanceToCenter = Math.abs(((otherCoord + 32) % 64 + 64) % 64 - 32);
                        const isCorridorHeight = (y >= h + 1 && y <= h + 3);
                        if (!(distanceToCenter <= 1 && isCorridorHeight)) {
                            chunk.setBlockLocal(lx, y, lz, 7); // 通路以外は白壁
                        }
                    }
                }
            }
        }
    }

    // 2. ランダムな石の構造物（4×3の壁）をチャンクに15%の確率で生成
    const stoneWallSeed = (cx * 1234567) ^ (cz * 7654321);
    if ((Math.abs(stoneWallSeed) % 100) < 15) {
        const sx = 4 + (Math.abs(stoneWallSeed >> 2) % (CHUNK_SIZE - 8));
        const sz = 4 + (Math.abs(stoneWallSeed >> 4) % (CHUNK_SIZE - 8));
        const dir = (stoneWallSeed % 2 === 0); // X方向またはZ方向に壁を伸ばす
        for (let i = 0; i < 4; i++) {
            for (let y = 6; y <= 8; y++) {
                const bx = dir ? sx + i : sx;
                const bz = dir ? sz : sz + i;
                chunk.setBlockLocal(bx, y, bz, 3); // 石ブロック
            }
        }
    }

    // 3. 木の生成（壁から2ブロック以上離れた草の上に6%の確率で配置）
    for (let lz = 2; lz < CHUNK_SIZE - 2; lz++) {
        for (let lx = 2; lx < CHUNK_SIZE - 2; lx++) {
            const worldX = cx * CHUNK_SIZE + lx;
            const worldZ = cz * CHUNK_SIZE + lz;

            // 壁の近くには木を置かない
            const isNearWallX = (worldX % 64 === 32 || worldX % 64 === -32 || worldX % 64 === 31 || worldX % 64 === -33);
            const isNearWallZ = (worldZ % 64 === 32 || worldZ % 64 === -32 || worldZ % 64 === 31 || worldZ % 64 === -33);
            if (isNearWallX || isNearWallZ) continue;

            const h = 5;
            if (chunk.getBlockLocal(lx, h, lz) === 1 &&
                chunk.getBlockLocal(lx, h + 1, lz) === 0 &&
                Math.random() < 0.06) {

                // 近くに木があれば生成しない（密生防止）
                let tooClose = false;
                for (let ox = -2; ox <= 2 && !tooClose; ox++) {
                    for (let oz = -2; oz <= 2 && !tooClose; oz++) {
                        if (chunk.getBlockLocal(lx + ox, h + 1, lz + oz) === 5) tooClose = true;
                    }
                }
                if (tooClose) continue;

                // 木の高さをランダムに決定（低・中・高の3段階）
                const rand = Math.random();
                let trunkHeight = rand < 0.2 ? 3 + Math.floor(Math.random() * 2)
                    : rand < 0.8 ? 5 + Math.floor(Math.random() * 2)
                        : 7 + Math.floor(Math.random() * 2);

                // 幹を配置
                for (let ty = 1; ty <= trunkHeight; ty++) {
                    chunk.setBlockLocal(lx, h + ty, lz, 5);
                }
                // 葉を配置（頂上は1ブロック半径、その下は2ブロック半径）
                for (let ly = trunkHeight - 1; ly <= trunkHeight + 1; ly++) {
                    const radius = (ly === trunkHeight + 1) ? 1 : 2;
                    for (let ldx = -radius; ldx <= radius; ldx++) {
                        for (let ldz = -radius; ldz <= radius; ldz++) {
                            // 角を丸める（正方形ではなくより丸い葉の形に）
                            if (Math.abs(ldx) === radius && Math.abs(ldz) === radius && ly < trunkHeight + 1) continue;
                            if (chunk.getBlockLocal(lx + ldx, h + ly, lz + ldz) === 0) {
                                chunk.setBlockLocal(lx + ldx, h + ly, lz + ldz, 6);
                            }
                        }
                    }
                }
            }
        }
    }

    worldChunks.set(getChunkKey(cx, cz), chunk);
    return chunk;
}

/**
 * チャンクのブロックデータから表示用Three.jsメッシュを構築する
 * 空気に隣接している面だけを追加する「フェイスカリング」で頂点数を最小化する
 */
function buildChunkMesh(chunk) {
    const positions = [];
    const texcoords = [];
    const normals = [];

    /**
     * ブロックIDと面インデックスからテクスチャアトラスのUV座標を返す
     * @param {number} blockType - ブロック種類ID
     * @param {number} faceIndex - 面方向 (0=下, 1=上, 2〜5=側面)
     */
    const getUVs = (blockType, faceIndex) => {
        let tx = 0, ty = 0; // アトラス内のタイル列・行
        if (blockType === 1) {          // 草: 上面は草、下面は土、側面は草側面
            if (faceIndex === 1) tx = 1;
            else if (faceIndex === 0) tx = 2;
            else tx = 0;
        } else if (blockType === 2) { tx = 2; } // 土
        else if (blockType === 3) { tx = 3; } // 石
        else if (blockType === 4) { tx = 0; ty = 1; } // ひび石
        else if (blockType === 5) {                        // 木: 上下は年輪、側面は縦縞
            if (faceIndex === 1 || faceIndex === 0) { tx = 0; ty = 2; }
            else { tx = 1; ty = 1; }
        } else if (blockType === 6) { tx = 2; ty = 1; } // 葉
        else if (blockType === 7) { tx = 3; ty = 1; } // 白壁

        const u0 = tx * 0.25, v0 = ty * 0.25;
        const u1 = u0 + 0.25, v1 = v0 + 0.25;
        // 2つの三角形（4頂点→6頂点分）のUV座標を返す
        return [u0, v0, u1, v0, u1, v1, u0, v0, u1, v1, u0, v1];
    };

    // 1枚の四角形ポリゴン（2三角形）を追加するヘルパー
    function addFace(p1, p2, p3, p4, normal, blockType, faceIndex) {
        positions.push(...p1, ...p2, ...p3, ...p1, ...p3, ...p4);
        texcoords.push(...getUVs(blockType, faceIndex));
        normals.push(...normal, ...normal, ...normal, ...normal, ...normal, ...normal);
    }

    // 6方向の法線ベクトル（下・上・左・右・前・後）
    const normalsArr = [
        [0, -1, 0], [0, 1, 0], [-1, 0, 0], [1, 0, 0], [0, 0, 1], [0, 0, -1]
    ];

    const cx = chunk.cx * CHUNK_SIZE;
    const cz = chunk.cz * CHUNK_SIZE;

    // 全ブロックを走査して、空気に隣接する面だけポリゴンを追加する
    for (let lz = 0; lz < CHUNK_SIZE; lz++) {
        for (let y = 0; y < CHUNK_HEIGHT; y++) {
            for (let lx = 0; lx < CHUNK_SIZE; lx++) {
                const block = chunk.getBlockLocal(lx, y, lz);
                if (block === 0) continue; // 空気ブロックはスキップ

                const wx = cx + lx;
                const wz = cz + lz;

                // 空気または葉を「透明」とみなす（葉越しに見えるため）
                const isTransparent = (b) => b === 0 || b === 6;

                // 6方向それぞれ隣が透明なら面を追加する
                if (isTransparent(getBlock(wx, y - 1, wz)))
                    addFace([wx, y, wz + 1], [wx + 1, y, wz + 1], [wx + 1, y, wz], [wx, y, wz], normalsArr[0], block, 0); // 下
                if (isTransparent(getBlock(wx, y + 1, wz)))
                    addFace([wx, y + 1, wz], [wx + 1, y + 1, wz], [wx + 1, y + 1, wz + 1], [wx, y + 1, wz + 1], normalsArr[1], block, 1); // 上
                if (isTransparent(getBlock(wx - 1, y, wz)))
                    addFace([wx, y + 1, wz + 1], [wx, y + 1, wz], [wx, y, wz], [wx, y, wz + 1], normalsArr[2], block, 2); // 左
                if (isTransparent(getBlock(wx + 1, y, wz)))
                    addFace([wx + 1, y + 1, wz], [wx + 1, y + 1, wz + 1], [wx + 1, y, wz + 1], [wx + 1, y, wz], normalsArr[3], block, 3); // 右
                if (isTransparent(getBlock(wx, y, wz + 1)))
                    addFace([wx + 1, y + 1, wz + 1], [wx, y + 1, wz + 1], [wx, y, wz + 1], [wx + 1, y, wz + 1], normalsArr[4], block, 4); // 前
                if (isTransparent(getBlock(wx, y, wz - 1)))
                    addFace([wx, y + 1, wz], [wx + 1, y + 1, wz], [wx + 1, y, wz], [wx, y, wz], normalsArr[5], block, 5); // 後
            }
        }
    }

    // 既存メッシュを削除してからシーンに新しいメッシュを追加
    if (chunk.mesh) {
        scene.remove(chunk.mesh);
        chunk.mesh.geometry.dispose();
        chunk.mesh = null;
    }
    if (positions.length > 0) {
        const geometry = new THREE.BufferGeometry();
        geometry.setAttribute('position', new THREE.BufferAttribute(new Float32Array(positions), 3));
        geometry.setAttribute('normal', new THREE.BufferAttribute(new Float32Array(normals), 3));
        geometry.setAttribute('uv', new THREE.BufferAttribute(new Float32Array(texcoords), 2));
        chunk.mesh = new THREE.Mesh(geometry, worldMaterial);
        scene.add(chunk.mesh);
    }
    chunk.needsUpdate = false;
}

// ============================================================
// 動的チャンクマネージャー
// プレイヤー周辺のチャンクを生成・破棄・メッシュ再構築する
// ============================================================

const RENDER_DISTANCE = 3; // プレイヤー中心から何チャンク先まで描画するか

/**
 * プレイヤー位置に基づいてチャンクの生成・破棄・再構築を行う
 * 毎フレーム呼ばれる
 */
function updateChunks(playerX, playerZ) {
    const pcx = Math.floor(playerX / CHUNK_SIZE);
    const pcz = Math.floor(playerZ / CHUNK_SIZE);

    // 1. 未生成チャンクを生成（ワールドは-6〜+5チャンクの固定範囲）
    for (let cx = -6; cx <= 5; cx++) {
        for (let cz = -6; cz <= 5; cz++) {
            if (!getChunk(cx, cz)) {
                generateChunk(cx, cz);
                // 隣接チャンクのメッシュも境界が変わるので再構築フラグを立てる
                [-1, 1].forEach(d => {
                    const nx = getChunk(cx + d, cz); if (nx) nx.needsUpdate = true;
                    const nz = getChunk(cx, cz + d); if (nz) nz.needsUpdate = true;
                });
            }
        }
    }

    // 2. プレイヤーから遠いチャンクをアンロード（メモリ節約）
    for (const [key, chunk] of worldChunks.entries()) {
        if (Math.abs(chunk.cx - pcx) > RENDER_DISTANCE + 1 ||
            Math.abs(chunk.cz - pcz) > RENDER_DISTANCE + 1) {
            if (chunk.mesh) {
                scene.remove(chunk.mesh);
                chunk.mesh.geometry.dispose();
            }
            worldChunks.delete(key);
        }
    }

    // 3. 更新フラグが立っているチャンクのメッシュを再構築
    for (const chunk of worldChunks.values()) {
        if (chunk.needsUpdate) buildChunkMesh(chunk);
    }
}

// ============================================================
// 物理演算・コリジョン
// プレイヤーとブロックの衝突判定
// ============================================================

/**
 * 指定座標にプレイヤーが存在するとブロックと重なるか判定する
 * @returns {boolean} ブロックに重なっている場合 true
 */
function checkCollision(px, py, pz) {
    const margin = 0.3;  // プレイヤーの水平方向の当たり判定半径
    const height = 1.55; // カメラ位置から足元までのオフセット

    // 足元・中心・頭部の3段階・四隅の12点でブロックを確認
    for (let dy = -height; dy <= 0.2; dy += 0.85) {
        for (let dx = -margin; dx <= margin; dx += margin * 2) {
            for (let dz = -margin; dz <= margin; dz += margin * 2) {
                if (getBlock(Math.floor(px + dx), Math.floor(py + dy), Math.floor(pz + dz)) !== 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

// ============================================================
// 弓矢物理エンジン
// 矢の発射・飛行・衝突・ブロックダメージ処理
// ============================================================

const GRAVITY = -15.0; // 重力加速度（毎秒）

/**
 * 弓を発射する
 * 溜め量によって射出速度・ダメージが変わる
 */
function shootArrow() {
    const p = gameState.player;
    if (gameState.ammo <= 0) return;         // 矢がない
    if (gameState.bowDurability <= 0) return; // 弓が壊れている

    const cosPitch = Math.cos(p.pitch);
    const sinPitch = Math.sin(p.pitch);
    const cosYaw = Math.cos(p.yaw);
    const sinYaw = Math.sin(p.yaw);

    // カメラの向きベクトルを計算
    const dir = {
        x: -sinYaw * cosPitch,
        y: sinPitch,
        z: -cosYaw * cosPitch
    };

    const power = 10 + gameState.charge * 28;   // 射出速度: 10〜38 m/s
    const damage = 5.0 + gameState.charge * 25.0; // ダメージ: 5〜30

    const yaw = Math.atan2(dir.x, dir.z);
    const pitch = -Math.asin(dir.y);

    gameState.arrows.push({
        x: p.x, y: p.y, z: p.z,
        vx: dir.x * power, vy: dir.y * power, vz: dir.z * power,
        yaw, pitch,
        damage,
        hit: false,
        life: 30.0, // 30秒後に自動消滅
        ownerId: socket.id
    });

    // サーバー経由で他プレイヤーにも矢を同期する
    if (socket.connected) {
        socket.emit('shootArrow', {
            x: p.x, y: p.y, z: p.z,
            vx: dir.x * power, vy: dir.y * power, vz: dir.z * power,
            yaw, pitch, damage
        });
    }

    gameState.ammo--;
    gameState.bowDurability--;
}

/**
 * 飛行中の全ての矢を毎フレーム更新する
 * 物理・衝突・回収・寿命消滅をまとめて処理する
 */
function updateArrows(deltaTime) {
    for (let i = gameState.arrows.length - 1; i >= 0; i--) {
        const arrow = gameState.arrows[i];

        if (arrow.hit) {
            // 刺さった矢: ブロックが破壊されたら落下開始
            if (arrow.hitX !== undefined && getBlock(arrow.hitX, arrow.hitY, arrow.hitZ) === 0) {
                arrow.hit = false;
                arrow.vx = arrow.vy = arrow.vz = 0;
                arrow.isFalling = true;
                arrow.angularVelocityPitch = 0;
                arrow.life = 10.0;
            }

            // 近づくと回収できる
            const dxp = arrow.x - gameState.player.x;
            const dyp = arrow.y - (gameState.player.y - 0.5);
            const dzp = arrow.z - gameState.player.z;
            if (dxp * dxp + dyp * dyp + dzp * dzp < 1.5 * 1.5) {
                gameState.ammo++;
                gameState.arrows.splice(i, 1);
            } else {
                arrow.life -= deltaTime;
                if (arrow.life <= 0) gameState.arrows.splice(i, 1);
            }
            continue;
        }

        // 矢と敵の衝突判定
        for (let j = gameState.enemies.length - 1; j >= 0; j--) {
            const enemy = gameState.enemies[j];
            const dx = arrow.x - enemy.x;
            const dy = arrow.y - enemy.y;
            const dz = arrow.z - enemy.z;
            if (dx * dx + dy * dy + dz * dz < 0.8 * 0.8) {
                enemy.health -= arrow.damage;
                if (socket.connected) socket.emit('enemyHit', { enemyId: enemy.id, damage: arrow.damage });
                arrow.hit = true;
                arrow.vx = arrow.vy = arrow.vz = 0;
                arrow.life = 5.0;
                if (enemy.health <= 0) gameState.enemies.splice(j, 1);
                break;
            }
        }
        if (arrow.hit) continue;

        // 矢とプレイヤー自身の衝突判定（発射直後は除外）
        const p = gameState.player;
        const dxp = arrow.x - p.x;
        const dyp = arrow.y - (p.y - 0.7);
        const dzp = arrow.z - p.z;
        if (dxp * dxp + dyp * dyp + dzp * dzp < 0.8 * 0.8 && arrow.life < 29.5) {
            if (arrow.ownerId && arrow.ownerId !== socket.id) {
                // 他プレイヤーの矢はサーバー経由でダメージを通知
                if (socket.connected) socket.emit('playerHit', { targetId: socket.id, damage: arrow.damage });
                p.health = Math.max(0, p.health - arrow.damage);
            } else if (!arrow.ownerId || arrow.ownerId === socket.id) {
                p.health = Math.max(0, p.health - arrow.damage);
            }
            arrow.hit = true;
            arrow.vx = arrow.vy = arrow.vz = 0;
            arrow.life = 1.0;
            continue;
        }

        // 飛行中の物理更新（先端の軌跡で精密コリジョン検出）
        const speed = Math.sqrt(arrow.vx ** 2 + arrow.vy ** 2 + arrow.vz ** 2);
        const nx = speed > 0.001 ? arrow.vx / speed : 0;
        const ny = speed > 0.001 ? arrow.vy / speed : 0;
        const nz = speed > 0.001 ? arrow.vz / speed : 0;

        const oldTipX = arrow.x + nx * 0.5;
        const oldTipY = arrow.y + ny * 0.5;
        const oldTipZ = arrow.z + nz * 0.5;

        arrow.x += arrow.vx * deltaTime;
        arrow.y += arrow.vy * deltaTime;
        arrow.z += arrow.vz * deltaTime;
        arrow.vy += GRAVITY * deltaTime; // 重力で矢が落下する

        const newSpeed = Math.sqrt(arrow.vx ** 2 + arrow.vy ** 2 + arrow.vz ** 2);
        const nnx = newSpeed > 0.001 ? arrow.vx / newSpeed : nx;
        const nny = newSpeed > 0.001 ? arrow.vy / newSpeed : ny;
        const nnz = newSpeed > 0.001 ? arrow.vz / newSpeed : nz;

        // 飛行中または落下中の矢の向きを速度方向に合わせる
        if (arrow.isFalling) {
            // 振り子モデルで先端が自然に下を向くよう回転させる
            const targetPitch = -Math.PI / 2;
            const angleDiff = arrow.pitch - targetPitch;
            arrow.angularVelocityPitch += -Math.sin(angleDiff) * 8.0 * deltaTime;
            arrow.angularVelocityPitch *= Math.max(0, 1.0 - 2.5 * deltaTime);
            arrow.pitch += arrow.angularVelocityPitch * deltaTime;
            arrow.pitch = Math.max(-Math.PI / 2, Math.min(Math.PI * 0.1, arrow.pitch));
        } else if (newSpeed > 0.001) {
            arrow.yaw = Math.atan2(arrow.vx, arrow.vz);
            arrow.pitch = -Math.asin(Math.max(-1, Math.min(1, arrow.vy / newSpeed)));
        }

        const newTipX = arrow.x + nnx * 0.5;
        const newTipY = arrow.y + nny * 0.5;
        const newTipZ = arrow.z + nnz * 0.5;

        // 先端の移動経路を細かく分割してブロックとの衝突を精密に検出
        const dx = newTipX - oldTipX;
        const dy = newTipY - oldTipY;
        const dz = newTipZ - oldTipZ;
        const dist = Math.sqrt(dx * dx + dy * dy + dz * dz);
        const steps = Math.max(1, Math.ceil(dist / 0.1));

        let hitBlockType = 0;
        let mx, my, mz;
        for (let s = 1; s <= steps; s++) {
            const tx = oldTipX + dx * (s / steps);
            const ty = oldTipY + dy * (s / steps);
            const tz = oldTipZ + dz * (s / steps);
            const b = getBlock(Math.floor(tx), Math.floor(ty), Math.floor(tz));
            if (b !== 0 && b !== 6) { // 空気と葉は無視
                hitBlockType = b;
                mx = Math.floor(tx); my = Math.floor(ty); mz = Math.floor(tz);
                // 矢を少しブロックに埋め込む（刺さった見た目に）
                const embedDepth = 0.2;
                arrow.x = tx - nnx * (0.5 - embedDepth);
                arrow.y = ty - nny * (0.5 - embedDepth);
                arrow.z = tz - nnz * (0.5 - embedDepth);
                arrow.hit = true;
                arrow.hitX = mx; arrow.hitY = my; arrow.hitZ = mz;
                arrow.vx = arrow.vy = arrow.vz = 0;
                arrow.life = 600.0; // 刺さった矢は10分後に消滅
                break;
            }
        }

        // ブロックダメージ（石ブロックのみ: 矢が当たるとHPが減りひび割れる）
        if (arrow.hit && hitBlockType !== 0) {
            if (hitBlockType === 3 || hitBlockType === 4) {
                const key = `${mx},${my},${mz}`;
                let hp = gameState.blockHealth.get(key) ?? 60.0;
                hp -= arrow.damage;
                gameState.blockHealth.set(key, hp);
                if (hp <= 0) {
                    // setBlock(mx, my, mz, 0); の代わりに以下を実行
                    const chunk = getChunk(Math.floor(mx / CHUNK_SIZE), Math.floor(mz / CHUNK_SIZE));
                    if (chunk) {
                        const lx = ((mx % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
                        const lz = ((mz % CHUNK_SIZE) + CHUNK_SIZE) % CHUNK_SIZE;
                        chunk.setBlockLocal(lx, my, lz, 0); // 直接書き換え（ドロップ処理なし）

                        // 他のプレイヤーにも同期（必要であれば）
                        if (socket.connected) socket.emit('breakBlock', { x: mx, y: my, z: mz });
                    }
                    gameState.blockHealth.delete(key);
                } else if (hp <= 30.0) {
                    setBlock(mx, my, mz, 4); // HPが半分以下でひび石に変化
                }
            }
        }

        arrow.life -= deltaTime;
        if (arrow.life <= 0) gameState.arrows.splice(i, 1);
    }
}

// ============================================================
// エンティティ（敵・矢）の3Dメッシュ管理
// ============================================================

// ブロック選択時のワイヤーフレームボックス（黒い縁取り）
const selectionBoxMaterial = new THREE.LineBasicMaterial({ color: 0x000000 });
const selectionBoxGeometry = new THREE.EdgesGeometry(new THREE.BoxGeometry(1.004, 1.004, 1.004));

// 敵のテクスチャ: 赤いキャンバスで作成（サンドバッグ的な存在）
const enemyTextureCanvas = document.createElement('canvas');
enemyTextureCanvas.width = enemyTextureCanvas.height = 64;
const eCtx = enemyTextureCanvas.getContext('2d');
eCtx.fillStyle = '#ff4757'; eCtx.fillRect(0, 0, 64, 64);
eCtx.fillStyle = '#ff6b81'; eCtx.fillRect(10, 10, 44, 44);
const enemyTex = new THREE.CanvasTexture(enemyTextureCanvas);
enemyTex.colorSpace = THREE.SRGBColorSpace;
enemyTex.magFilter = THREE.NearestFilter;
const enemyMaterial = new THREE.MeshStandardMaterial({ map: enemyTex });
const enemyGeometry = new THREE.BoxGeometry(0.8, 0.8, 0.8);

// 矢のテクスチャ: 茶色のシンプルな直方体
const arrowTextureCanvas = document.createElement('canvas');
arrowTextureCanvas.width = arrowTextureCanvas.height = 16;
const aCtx = arrowTextureCanvas.getContext('2d');
aCtx.fillStyle = '#8B4513'; aCtx.fillRect(0, 0, 16, 16);
const arrowTex = new THREE.CanvasTexture(arrowTextureCanvas);
arrowTex.colorSpace = THREE.SRGBColorSpace;
arrowTex.magFilter = THREE.NearestFilter;
const arrowMaterial = new THREE.MeshStandardMaterial({ map: arrowTex });
const arrowGeometry = new THREE.BoxGeometry(0.1, 0.1, 1.0);

// シーン上のエンティティメッシュを一元管理するオブジェクト
const instancedEntities = {
    selectionBox: new THREE.LineSegments(selectionBoxGeometry, selectionBoxMaterial),
    enemyMeshes: [],  // 現在シーンにある敵メッシュの配列
    arrowMeshes: []   // 現在シーンにある矢メッシュの配列
};
scene.add(instancedEntities.selectionBox);

// ============================================================
// メインゲームループ (update・render)
// ============================================================

/**
 * ゲームのロジック更新（毎フレーム呼ばれる）
 * プレイヤー移動・物理・採掘・弓チャージ・UI更新を担当
 */
function update(deltaTime) {

    const p = gameState.player;
    let baseSpeed = 5.0;

    // Shiftが押されていて前進中のみダッシュ有効（後退・停止で自動解除）
    if (p.isDashing && (!gameState.keys['KeyW'] || gameState.keys['KeyS'])) {
        p.isDashing = false;
    }
    if (p.isDashing) baseSpeed *= 1.8;

    const speed = baseSpeed * deltaTime;

    // WASDの入力方向を取得
    let dirX = 0, dirZ = 0;

    // 弓チャージ: 右クリック押しっぱなしで毎フレーム0.66秒かけて1.0まで増加
    if (gameState.isCharging) {
        gameState.charge = Math.min(1.0, gameState.charge + deltaTime * 1.5);
    }

    if (gameState.keys['KeyW']) dirZ -= 1;
    if (gameState.keys['KeyS']) dirZ += 1;
    if (gameState.keys['KeyA']) dirX -= 1;
    if (gameState.keys['KeyD']) dirX += 1;

    const sinYaw = Math.sin(p.yaw);
    const cosYaw = Math.cos(p.yaw);

    if (dirX !== 0 || dirZ !== 0) {
        // 斜め移動が速くならないよう方向を正規化
        const length = Math.sqrt(dirX * dirX + dirZ * dirZ);
        dirX /= length; dirZ /= length;

        // 入力方向をカメラの向きに合わせてワールド座標に変換
        const worldDirX = dirX * cosYaw + dirZ * sinYaw;
        const worldDirZ = -dirX * sinYaw + dirZ * cosYaw;

        if (p.isGrounded) {
            // 地上: 即座に最大速度に達するレスポンスの良い移動
            p.velocity.x = worldDirX * baseSpeed;
            p.velocity.z = worldDirZ * baseSpeed;
            if (!checkCollision(p.x + p.velocity.x * deltaTime, p.y, p.z)) p.x += p.velocity.x * deltaTime;
            if (!checkCollision(p.x, p.y, p.z + p.velocity.z * deltaTime)) p.z += p.velocity.z * deltaTime;
        } else {
            // 空中: 緩やかな加速（空気抵抗で壁キックの勢いを活かす）
            const airAccel = 8.0;
            p.velocity.x += worldDirX * airAccel * deltaTime;
            p.velocity.z += worldDirZ * airAccel * deltaTime;
        }
    } else if (p.isGrounded) {
        // 入力なし＆地上: 即座に停止
        p.velocity.x = 0;
        p.velocity.z = 0;
    }

    // 空中の水平速度移動と空気抵抗
    if (!p.isGrounded) {
        if (!checkCollision(p.x + p.velocity.x * deltaTime, p.y, p.z)) p.x += p.velocity.x * deltaTime;
        else p.velocity.x = 0;
        if (!checkCollision(p.x, p.y, p.z + p.velocity.z * deltaTime)) p.z += p.velocity.z * deltaTime;
        else p.velocity.z = 0;
        const airDrag = 1.5;
        p.velocity.x -= p.velocity.x * airDrag * deltaTime;
        p.velocity.z -= p.velocity.z * airDrag * deltaTime;
    }
    // 微小な速度はゼロにして浮動小数点のズレを防ぐ
    if (Math.abs(p.velocity.x) < 0.01) p.velocity.x = 0;
    if (Math.abs(p.velocity.z) < 0.01) p.velocity.z = 0;

    // 重力と垂直方向の衝突処理
    p.velocity.y -= 15.0 * deltaTime;
    const moveY = p.velocity.y * deltaTime;
    if (!checkCollision(p.x, p.y + moveY, p.z)) {
        p.y += moveY;
        p.isGrounded = false;
    } else {
        if (p.velocity.y < 0) {
            // 着地: 足元にスナップして接地フラグを立てる
            p.isGrounded = true;
            p.y = Math.floor(p.y - 1.55) + 1.55 + 0.001;
        } else {
            // 天井への衝突: 天井にスナップして速度を0に
            p.y = Math.ceil(p.y) - 0.001;
        }
        p.velocity.y = 0;
    }

    // ジャンプ・壁ジャンプ処理
    const now = performance.now();
    if (gameState.keys['Space']) {
        if (p.isGrounded) {
            p.velocity.y = 6.5; // 通常ジャンプ
            p.lastJumpTime = now;
        } else if (now - p.lastJumpTime > 250) {
            // 壁ジャンプ: 正面と左右斜めの3方向にレイキャストして壁を探す
            const cosPitch = Math.cos(p.pitch);
            const sinPitch = Math.sin(p.pitch);
            const mainDir = { x: -sinYaw * cosPitch, y: -sinPitch, z: -cosYaw * cosPitch };
            const sideDir = { x: cosYaw, y: 0, z: -sinYaw };

            const rays = [
                mainDir,
                { x: mainDir.x + sideDir.x * 0.2, y: mainDir.y, z: mainDir.z + sideDir.z * 0.2 },
                { x: mainDir.x - sideDir.x * 0.2, y: mainDir.y, z: mainDir.z - sideDir.z * 0.2 }
            ];

            let wallHit = null;
            for (const rDir of rays) {
                const hit = raycast({ x: p.x, y: p.y, z: p.z }, rDir, 8.0);
                if (hit.hit && (hit.norm[0] !== 0 || hit.norm[2] !== 0)) {
                    const dx = hit.x + 0.5 - p.x;
                    const dy = hit.y + 0.5 - p.y;
                    const dz = hit.z + 0.5 - p.z;
                    if (dx * dx + dy * dy + dz * dz < 9.0) wallHit = hit;
                }
            }
            if (wallHit && checkCollision(p.x - wallHit.norm[0] * 0.7, p.y, p.z - wallHit.norm[2] * 0.7)) {
                // 壁の法線方向に弾き飛ばしながら上昇
                p.velocity.y = 8.0;
                p.velocity.x = wallHit.norm[0] * 5.5;
                p.velocity.z = wallHit.norm[2] * 5.5;
                p.lastJumpTime = now;
            }
        }
        gameState.keys['Space'] = false; // ホールドジャンプを防ぐ
    }

    // 落下死判定: Y=-10以下で初期位置にテレポート
    if (p.y < -10) {
        p.y = 15; p.x = 0; p.z = 0; p.velocity.y = 0;
    }

    // カーソルが向いているブロックをレイキャストで更新
    const dir = {
        x: -sinYaw * Math.cos(p.pitch),
        y: Math.sin(p.pitch),
        z: -cosYaw * Math.cos(p.pitch)
    };
    gameState.targetBlock = raycast({ x: p.x, y: p.y, z: p.z }, dir, 8.0);

    // 採掘進捗処理
    if (gameState.isMouseDown0 && gameState.targetBlock?.hit) {
        const { x, y, z } = gameState.targetBlock;
        const block = getBlock(x, y, z);
        // ブロック種類ごとの採掘時間（秒）
        const targetTime = block === 5 ? 1.0 : block === 6 ? 0.5 : block === 3 ? 2.0 : 0;

        if (targetTime > 0) {
            if (gameState.miningTarget?.x === x && gameState.miningTarget?.y === y && gameState.miningTarget?.z === z) {
                gameState.miningProgress += deltaTime;
                if (gameState.miningProgress >= targetTime) {
                    setBlock(x, y, z, 0);
                    gameState.miningProgress = 0;
                    gameState.miningTarget = null;
                }
            } else {
                gameState.miningTarget = { x, y, z };
                gameState.miningProgress = 0;
            }
        } else {
            gameState.miningProgress = 0;
            gameState.miningTarget = null;
        }
    } else {
        gameState.miningProgress = 0;
        gameState.miningTarget = null;
    }

    updateArrows(deltaTime);
    updateDroppedItems(deltaTime);
    updateHotbarUI();

    // 弓チャージバーのUIアニメーション
    const chargeBarContainer = document.getElementById('charge-bar-container');
    const chargeBar = document.getElementById('charge-bar');
    if (chargeBarContainer && chargeBar) {
        if (gameState.isCharging) {
            chargeBarContainer.style.opacity = '1';
            chargeBarContainer.style.transform = 'translateX(-50%) scale(1)';
            chargeBar.style.width = `${gameState.charge * 100}%`;
            // 満タンになったら黄色に変化
            chargeBar.style.backgroundColor = gameState.charge >= 1.0 ? '#fffa65' : '#ffffff';
            // 手に持つアイテムを後ろに引いてチャージ感を演出
            heldItemContainer.position.z = -0.5 + gameState.charge * 0.1;
            heldItemContainer.rotation.x = 0.2 + gameState.charge * 0.1;
        } else {
            chargeBarContainer.style.opacity = '0';
            chargeBarContainer.style.transform = 'translateX(-50%) scale(0.8)';
            // lerpでなめらかに元の位置に戻す
            heldItemContainer.position.z = THREE.MathUtils.lerp(heldItemContainer.position.z, -0.5, 0.2);
            heldItemContainer.rotation.x = THREE.MathUtils.lerp(heldItemContainer.rotation.x, 0, 0.2);
        }
    }

    // 手に持つアイテムのアイドルボブ（上下・左右に微かに揺れる）
    if (!gameState.isCharging && gameState.isRunning) {
        heldItemContainer.position.y = -0.3 + Math.sin(performance.now() * 0.005) * 0.01;
        heldItemContainer.position.x = 0.35 + Math.cos(performance.now() * 0.002) * 0.005;
    }

    // HPバーの更新（残量に応じて色が変わる: 緑→オレンジ→赤）
    const hpBarFill = document.getElementById('hp-bar-fill');
    const hpValue = document.getElementById('hp-value');
    if (hpBarFill) {
        const hpPercent = Math.max(0, gameState.player.health) / 100 * 100;
        hpBarFill.style.width = `${hpPercent}%`;
        if (hpValue) hpValue.innerText = Math.ceil(Math.max(0, gameState.player.health));
        hpBarFill.style.backgroundColor =
            hpPercent <= 30 ? '#ff4757' :  // 30%以下: 赤
                hpPercent <= 50 ? '#ffa502' :  // 50%以下: オレンジ
                    '#2ed573';   // それ以外: 緑
    }

    // デバッグ情報: 現在のXYZ座標を画面左上に表示
    const debugInfo = document.getElementById('debug-info');
    if (debugInfo) {
        debugInfo.innerText = `XYZ: ${p.x.toFixed(1)} / ${p.y.toFixed(1)} / ${p.z.toFixed(1)}`;
    }

    // 死亡判定: HP0以下でゲームオーバー画面を表示
    if (p.health <= 0) {
        gameState.isRunning = false;
        document.exitPointerLock();
        titleScreen.classList.add('active');
        hud.style.display = 'none';
    }

    // 毎フレームサーバーにプレイヤー位置を送信
    if (socket.connected) {
        socket.emit('playerMovement', {
            x: p.x, y: p.y, z: p.z,
            pitch: p.pitch, yaw: p.yaw
        });
    }
}

// ============================================================
// レンダリング処理
// ゲーム状態をThree.jsシーンに反映して描画する
// ============================================================

/**
 * ゲーム状態に基づいてシーンを更新しフレームを描画する
 */
function render() {
    // カメラをプレイヤーの位置・向きと同期
    camera.position.set(gameState.player.x, gameState.player.y, gameState.player.z);
    camera.rotation.set(gameState.player.pitch, gameState.player.yaw, 0, 'YXZ');

    // ブロック選択枠: 照準が当たっているブロックの上に表示
    if (gameState.targetBlock?.hit) {
        instancedEntities.selectionBox.visible = true;
        instancedEntities.selectionBox.position.set(
            gameState.targetBlock.x + 0.5,
            gameState.targetBlock.y + 0.5,
            gameState.targetBlock.z + 0.5
        );
    } else {
        instancedEntities.selectionBox.visible = false;
    }

    // 矢メッシュ数をgameState.arrowsの数に合わせて追加・削除
    while (instancedEntities.arrowMeshes.length < gameState.arrows.length) {
        const m = new THREE.Mesh(arrowGeometry, arrowMaterial);
        scene.add(m);
        instancedEntities.arrowMeshes.push(m);
    }
    while (instancedEntities.arrowMeshes.length > gameState.arrows.length) {
        scene.remove(instancedEntities.arrowMeshes.pop());
    }
    for (let i = 0; i < gameState.arrows.length; i++) {
        const a = gameState.arrows[i];
        const m = instancedEntities.arrowMeshes[i];
        m.position.set(a.x, a.y, a.z);
        m.rotation.set(a.pitch, a.yaw, 0, 'YXZ');
    }

    // 敵メッシュ数をgameState.enemiesの数に合わせて追加・削除
    while (instancedEntities.enemyMeshes.length < gameState.enemies.length) {
        const m = new THREE.Mesh(enemyGeometry, enemyMaterial);
        scene.add(m);
        instancedEntities.enemyMeshes.push(m);
    }
    while (instancedEntities.enemyMeshes.length > gameState.enemies.length) {
        scene.remove(instancedEntities.enemyMeshes.pop());
    }
    for (let i = 0; i < gameState.enemies.length; i++) {
        const e = gameState.enemies[i];
        instancedEntities.enemyMeshes[i].position.set(e.x, e.y, e.z);
    }

    renderer.render(scene, camera); // Three.jsにシーンを描画させる
}

/**
 * メインゲームループ（requestAnimationFrameで毎フレーム呼ばれる）
 */
function gameLoop(now) {
    if (!gameState.isRunning) return;

    const deltaTime = (now - gameState.lastTime) / 1000; // ミリ秒→秒に変換
    gameState.lastTime = now;

    updateChunks(gameState.player.x, gameState.player.z); // チャンク管理
    update(deltaTime);  // ゲームロジック更新
    render();           // 描画

    requestAnimationFrame(gameLoop); // 次フレームを予約
}

// 初回描画（ゲーム開始前に画面を一度クリア）
render();