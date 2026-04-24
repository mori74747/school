#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int mkBinSearchTree(Tree **root, int data);
void printUpOrder(Tree *root);
void printDownOrder(Tree *root);

main()
{
  Tree *root, *node;
  int data, found;

  root = getEmptyTree();
  // 既に格納されているデータを入力するまで二分探索木の生成を続ける 
  do {
    data = getint("追加データ: ");         // データの入力                             
    putchar('\n');
    found = mkBinSearchTree(&root, data);  // 二分探索木の生成                         
    printf("found: %d\n\n", found);
    printTree(root);                       // 木の表示                                 
    putchar('\n');
  } while (found == 0);                    // 入力データが既に存在していれば終了 
  
  printf("昇順：");
  printUpOrder(root);                      // ノードの値を昇順に表示 
  putchar('\n');
  printf("降順：");                        // ノードの値を降順に表示 
  printDownOrder(root);
  printf("\n\n");
  
  rmTree(&root); // 生成した二分探索木を削除して終了

  return(0);
}

//--------------------------------------------------------------------------
//  二分探索木を生成する
//  ［引　数］root : データを追加する二分探索木のルートへのポインタ
//            data : 追加する整数データ
//
//  ［戻り値］data が既に木に格納されているとき(探索成功)      :  1
//            data が新たに木へ追加されたとき(探索失敗)        :  0
//            新規ノードの追加に失敗したとき(ノード生成に失敗) : -1
//--------------------------------------------------------------------------
int mkBinSearchTree(Tree **root, int data)
{
  Tree *new_node;
  int found;
  
  if (isEmptyTree(*root)) {  // 対象データがまだ木に格納されていないとき 
    *root = createNode(data);
    if (isEmptyTree(*root)) {
      return(-1);            // ノード生成に失敗した
    }
    found = 0;
  } else {			
    if (data <                   ) {
      // 対象データが部分木の根の値より小さいとき 
      found =                                                  ;
    } else if (data > getNodeData(*root)) {
      // 対象データが部分木の根の値より大きいとき 
      found =                                                  ;
    } else {
      // 対象データが部分木の根の値と一致したとき 
      found = 1;
    }
  }
  return(found);
}

//--------------------------------------------------------------------------
//  二分探索木内の全ノードの値を昇順(小さい順)に表示をする
//  ［引　数］root：木の根を指すポインタ
//  ［戻り値］なし
//
//  ［機　能］全ノードの値を昇順(小さい順)に横一列に空白区切りで表示する。
//　　　　　　表示後、改行はしない。
//--------------------------------------------------------------------------
void printUpOrder(Tree *root)
{
}

//--------------------------------------------------------------------------
//  二分探索木内の全ノードの値を降順(大きい順)に表示をする
//  ［引　数］root：木の根を指すポインタ
//  ［戻り値］なし
//
//  ［機　能］全ノードの値を降順(大きい順)に横一列に空白区切りで表示する。
//　　　　　　表示後、改行はしない。
//--------------------------------------------------------------------------
void printDownOrder(Tree *root)
{
  return;
}
