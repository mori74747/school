#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "list.h"

main()
{
  int data, i, n;
  List *head;
  
  head = getEmptyList();

  n = getint("データの個数：");             // リストに格納するデータの個数 
  for (i = 1; i <= n; i++) {
    data = getint("Input data: ");          // 新しいセルへ格納するデータの入力 
    if (insertHead(&head, data) == 0) {     // リストの先頭に新しいセルを挿入 
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    } else {
      printList(head);
      putchar('\n');
    }
  }
  putchar('\n');

  // 全てのセルを削除するまで、削除を繰り返す 
  do {
    printList(head);                       // リストの状態を確認 
    putchar('\n');
  } while (removeHead(&head) == 1);        // 先頭のセルを削除 
  
  return(0);
}
