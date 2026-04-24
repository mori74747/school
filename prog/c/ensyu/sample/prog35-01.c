#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "tree.h"

int mkBinSearchTree(Tree **root, int data);
int rmBinSearchTreeNode(Tree **root, int data);
Tree **maxValueNode(Tree **root);

main()
{
  Tree *root, *node;
  int data, found;

  root = getEmptyTree();
  do { // 二分探索木を生成する
    data = getint("追加データ: ");
    putchar('\n');
    found = mkBinSearchTree(&root, data);
    printf("found: %d\n\n", found);
    printTree(root);
    putchar('\n');
  } while (found == 0);
  // 既に存在するデータを追加すると終了

  do { // 二分探索木から指定した節を削除する
    data = getint("削除データ: ");            // 削除するデータの値を入力
    putchar('\n');
    found = rmBinSearchTreeNode(&root, data); // 削除に成功すれば TURE
    printf("found: %d\n\n", found);
    printTree(root);                          // バランス木の表示
    putchar('\n');
    // 削除対象のデータが存在しないか、または空木になるまで繰り返す
  } while (found == 1 && !isEmptyTree(root));

  rmTree(&root); // 生成した二分探索木を削除して終了

  return(0);
}

//--------------------------------------------------------------------------
//  二分探索木を生成する(この中には同じ値を持つノードは複数存在しない)
//  ［引　数］root : データを追加する二分探索木のルートへのポインタ
//            data : 追加する整数データ
//
//  ［戻り値］data が既に木に格納されているとき(探索成功)      :  1
//            data が新たに木へ追加されたとき(探索失敗)        :  0
//            新規ノードの追加に失敗したとき(ノード生成に失敗) : -1
//--------------------------------------------------------------------------
int mkBinSearchTree(Tree **root, int data)
{
  //
  // prog34-01.c の mkBinSearchTree() をここにコピーする
  //
}

//--------------------------------------------------------------------------
//  二分探索木から指定した値を持つノードを削除
//  ［引　数］root   : 削除対象の二分探索木のルートへのポインタ
//            target : 削除する整数データ
//
//  ［戻り値］target が存在し、削除が成功したとき     : 1
//            target がが存在せず、削除に失敗したとき : 0
//--------------------------------------------------------------------------
int rmBinSearchTreeNode(Tree **root, int target)
{
  Tree *rm_node, **maxvalue_node;
  int found;
  
  if (isEmptyTree(*root)) {// 指定した値を持つノードは存在しない 
    found = 0;
  } else if (target <                   ) {
    // 指定した値を持つノードを左部分木から探す 
    found =                                                        ;
  } else if (target >                   ) {
    // 指定した値を持つノードを右部分木から探す 
    found =                                                        ;
  } else {
    // 指定した値を持つノードが見つかった 
    rm_node = *root;
    if (isEmptyTree(getSubTree(rm_node, 'R'))) {
      // 削除ノードが右部分木を持たないとき、削除ノードの左部分木でつなぎ替える 
      *root =                         ;
      freeNode(        );
    } else if (isEmptyTree(getSubTree(rm_node, 'L'))) {
      // 削除ノードが左部分木を持たないとき、削除ノードの右部分木でつなぎ替える 
      *root =                         ;
      freeNode(        );
    } else {
      // 削除ノードが２つの子を持つとき、左部分木の最大値(最右端)で置き換える 
      maxvalue_node = maxValueNode(                         );
      setNodeData(     ,                            );
      rm_node =               ;
      *maxvalue_node =                                ;
      freeNode(        );
    }
    found = 1;
  }
  return(found);
}

//--------------------------------------------------------------------------
//  最大値を保持するノード(最右端ノード)を探す
//  ［引　数］root : 最大値を探す木のルートを保持するポインタ
//  ［戻り値］最大値のノードを指すポインタを保持するポインタ
//            ただし、rootが空木のときはNULLポインタ
//--------------------------------------------------------------------------
Tree **maxValueNode(Tree **root)
{
  if (isEmptyTree(*root)) {
    return(NULL);
  } else if (!isEmptyTree(                      )) {
    return(                                        );
  } else {
    return(root);
  }
}
