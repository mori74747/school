#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "list.h"

void removeList(List **head);

main()
{
  int data, i, n;
  List *head, *rhead;
  
  head = getEmptyList();

  n = getint("データの個数："); // リストに格納するデータの個数
  
  for (i = 1; i <= n; i++) {
    data = getint("Input data: ");       // 新しいセルへ格納するデータの入力
    if (appendTail(&head, data) == 0) {  // 新しいセルの挿入
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    }
  }
  rhead = reverseList(head);

  putchar('\n');
  printList(head);   // 最初に作ったリストのの確認
  putchar('\n');
  printList(rhead);  // 逆順にしたリストのの確認
  putchar('\n');

  // 最後に作ったリストを全て削除する
  removeList(&head);
  removeList(&rhead);

  return(0);
}
