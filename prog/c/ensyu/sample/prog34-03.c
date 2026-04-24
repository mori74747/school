#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int mkBinSearchTree(Tree **root, int data);

main()
{
  Tree *root;
  int n, i, data, found;

  n = getint("データ数: ");
  putchar('\n');
  root = getEmptyTree();
  for (i = 1; i <= n; i++) {
    data = getint("追加データ: ");         // データの入力     
    found = mkBinSearchTree(&root, data);  // 二分探索木の生成 
    putchar('\n');
    printf("found: %d\n\n", found);
    printTree2(root);                      // 木の表示         
    putchar('\n');
  }
  
  rmTree(&root); // 生成した二分探索木を削除して終了

  return(0);
}

//--------------------------------------------------------------------------------
//  二分探索木を生成する(既に格納されている値のときはノードカウンタ１つ増やす)
//  ［引　数］root : データを追加する二分探索木のルートへのポインタ
//            data : 追加する整数データ
//
//  ［戻り値］data が既に木に格納されているとき(探索成功)      :  1
//            data が新たに木へ追加されたとき(探索失敗)        :  0
//            新規ノードの追加に失敗したとき(ノード生成に失敗) : -1
//--------------------------------------------------------------------------------
int mkBinSearchTree(Tree **root, int data)
{
}
