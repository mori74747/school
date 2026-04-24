#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "list.h"

main()
{
  int data, i, n;
  List *head;
  
  head = getEmptyList();

  n = getint("データの個数：");          // リストに格納するデータの個数 
  
  for (i = 1; i <= n; i++) {
    data = getint("Input data: ");       // 新しいセルへ格納するデータの入力 
    if (insertHead(&head, data) == 0) {  // 新しいセルの挿入 
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    }
  }
  putchar('\n');
  printList(head);  // リストのの確認 
  putchar('\n');

  // 全てのセルを削除するまで、削除を繰り返す 
  do {
    putchar('\n');
    data = getint("remove data: ");        // 削除データの入力 
    putchar('\n');
    if (removeSearch(&head, data) == 0) {  // 該当セルの削除 
      fprintf(stderr, "%dは存在しません。\n", data);
    } else {
      printList(head);  // 削除結果の確認 
      putchar('\n');
    }
  } while(!isEmptyList(head));

  return(0);
}
