#include <stdio.h>
#include <hamakou.h>
#include "stack.h"

main()
{
  Stack x;
  int data, state;
  
  initStack(&x);                     // スタックを空にする
  
  putchar('\n');

  do {                               // スタックが一杯になるまでデータを格納する
    data = getint("push data : ");   // データ入力
    state = push(&x, data);          // 入力データを格納
  } while (state == 1);
  
  putchar('\n');                     // 見やすくするための改行

  state = pop(&x, &data);            // データを取り出し
  while (state == 1) {               // スタックが空になるまで続けてデータを取り出す
    printf("pop data : %d\n", data); // 取り出したデータの表示
    state = pop(&x, &data);
  }
  return(0);
}
