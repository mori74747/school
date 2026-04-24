//
//  ｎ個のノードからなるバランスされた木を作り、それを完全に削除する
//
#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

main()
{
  Tree *root;
  int n, stat;

  n = getint("ノードの数: ");       // ノードの総数を入力
  stat = mkBalanceTree(&root, n);   // ノード数ｎのバランス木を作る
  putchar('\n');                    // 見やすくするために改行
  printf("stat: %d\n\n", stat);     // 正しく作られたか戻り値を確認

  printf("生成したバランス木\n\n");
  printTree(root);                  // 木を表示
  putchar('\n');                    // 見やすくするために改行

  rmTree(&root);                    // 木を完全に削除
  printf("削除後\n\n");
  printTree(root);                  // 削除できていれば何も表示されない

  return(0);
}
