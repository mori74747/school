#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "list.h"

main()
{
  int data, i;
  List *head;
  
  head = getEmptyList();

  printf("Input data ([CTRL]+[D]で終了): ");

  while(scanf("%d", &data) != EOF) {     // 新しいセルへ格納するデータの入力([CTRL]+[D]で終了)
    if (insertHead(&head, data) == 0) {  // 新しいセルの挿入
      fprintf(stderr, "Error: セルを追加できませんでした。\n");
      break;
    }
    printf("\n現在のリスト: ");
    printList(head); // リストの状態を確認
    printf("\n\n");
    printf("リスト内のデータ数: %d\n", countCells(head));
    printf("データの合計: %d\n\n", sumOfCellsData(head));

    printf("Input data ([CTRL]+[D]で終了): ");
  }
  printf("\n\n");

  removeList(&head); // リスト内のセルをすべて削除
  
  return(0);
}
