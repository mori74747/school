#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int mkBinSearchTree(Tree **root, int data);
int rmBinSearchTreeNode(Tree **root, int target);

main()
{
  Tree *root;
  int n, i, data, found;

  n = getint("データ数: ");
  putchar('\n');
  root = getEmptyTree();
  for (i = 1; i <= n; i++) {
    data = getint("追加データ: ");             // データの入力
    putchar('\n');
    found = mkBinSearchTree(&root, data);      // 二分探索木の生成
    printf("found: %d\n\n", found);
    printTree2(root);                          // 木の表示(データ数付き)
    putchar('\n');
  }

  do { // 二分探索木から指定した節を削除する
    data = getint("削除データ: ");             // 削除するデータの値を入力
    putchar('\n');
    found = rmBinSearchTreeNode(&root, data);  // 削除に成功すれば 1
    printf("found: %d\n\n", found);
    printTree2(root);                          // バランス木の表示(データ数付き)
    putchar('\n');
    // 削除対象のデータが存在しないか、または空木になるまで繰り返す
  } while (found == 1 && !isEmptyTree(root));

  rmTree(&root); // 生成した二分探索木を削除して終了

  return(0);
}

//--------------------------------------------------------------------------------
//  二分探索木を生成する(既に格納されている値のときはノードカウンタを1つ増やす）
//  ［引　数］root : データを追加する二分探索木のルートへのポインタ
//            data : 追加する整数データ
//
//  ［戻り値］data が既に木に格納されているとき(探索成功)      :  1
//            data が新たに木へ追加されたとき(探索失敗)        :  0
//            新規ノードの追加に失敗したとき(ノード生成に失敗) : -1
//--------------------------------------------------------------------------------
int mkBinSearchTree(Tree **root, int data)
{
  //
  // prog34-03.c の mkBinSearchTree() をここにコピーする
  //
}

//--------------------------------------------------------------------------------
//  二分探索木から指定した値を持つノードを削除
//  ［引　数］root   : 削除対象の二分探索木のルートへのポインタ
//            target : 削除する整数データ
//
//  ［戻り値］target が存在し、削除が成功したとき     : 1
//            target がが存在せず、削除に失敗したとき : 0
//--------------------------------------------------------------------------------
int rmBinSearchTreeNode(Tree **root, int target)
{
}
