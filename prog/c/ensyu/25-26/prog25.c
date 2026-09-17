#include <stdio.h>
#include <hamakou.h>
#include "queue.h"

main()
{
  int i, data, state;
  Queue queue;
  
  initQueue(&queue); // キューを空にする

  // リングバッファが正しく動作しているのを確かめるために２回繰り返す 
  for (i = 1; i <= 2; i++) {
    // キューが満杯になるまでデータを格納する 
    do {
      data = getint("in data : ");        // データ入力    
    } while (enQueue(&queue, data) == 1); // キューが満杯になるまでデータを格納する

    putchar('\n');

    while (deQueue(&queue, &data) == 1) { // キューが空になるまでデータを取り出し続ける 
      printf("out data : %d\n", data);    // 取り出したデータの表示 
    }

    putchar('\n');
  }
  return(0);
}
