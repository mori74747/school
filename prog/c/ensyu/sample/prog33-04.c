//
//  木から指定した値を持つノードをすべて削除するプログラム
//  （注：このプログラムでは、削除した結果バランス木はくずれる）
// 
#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int rmSearchNodeAll(Tree **root, int target);
Tree **mostLeftLeafRoot(Tree **root);

main()
{
    Tree *root;
    int n, x, stat;

    n = getint("ノードの数: ");                 // ノードの総数を入力
    stat = mkBalanceTree(&root, n);             // ノード数ｎのバランス木を作る
    putchar('\n');                              // 見やすくするために改行
    printf("stat: %d\n\n", stat);               // 正しく作られたか戻り値を確認
    printTree(root);                            // バランス木の表示
    putchar('\n');                              // 見やすくするために改行
    do {
        x = getint("削除データ: ");             // 削除するデータの値を入力
        stat = rmSearchNodeAll(&root, x);       // 削除に成功すれば       1
        putchar('\n');                          // 見やすくするために改行
        printf("stat = %d\n\n", stat);          // データが存在しなければ 0
        printTree(root);                        // バランス木の表示
        putchar('\n');                          // 見やすくするために改行
    } while (!isEmptyTree(root));               // 全ノードを削除するまで繰り返す

    return(0);
}

//-------------------------------------------------------------------------------
//  木から指定した値を持つノードをすべて削除する
//  ［引　数］root   : 削除対象の木のルートへのポインタ
//            target : 削除する整数データ
//
//  ［戻り値］target が存在し、削除が成功したとき     : 1
//            target がが存在せず、削除に失敗したとき : 0
//-------------------------------------------------------------------------------
int rmSearchNodeAll(Tree **root, int target)
{
}

//-------------------------------------------------------------------------------
//  最左端のリーフを指すポインタを保持している領域のアドレスを取得する
//  ［引　数］root : 最左端を探す対象となる木のルートを指すポインタ
//  ［戻り値］最左端のリーフを指すポインタを保持している領域のアドレス
//            ただし、rootが空リストのときはNULLポインタ
//-------------------------------------------------------------------------------
Tree **mostLeftLeafRoot(Tree **root)
{
}
