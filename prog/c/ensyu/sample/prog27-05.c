#include <stdio.h>
#include <hamakou.h>
#include "stack27.h"

main()
{
  Stack x;
  int i, num, data, state;
  
  initStack(&x);                     // スタックの初期化 
  
  num = getint("スタックに格納するデータ数：");

  for (i = 0; i < num; i++) {        // スタックに指定した個数のデータを格納する 
    data = getint("push data : ");   // データ入力       
    state = push(&x, data);          // 入力データを格納 
  }
  
  putchar('\n');                     // 見やすくするための改行

  state = pop(&x, &data);            // データの取り出し 
  while (state == 1) {               // スタックが空になるまでデータを取り出す 
    printf("pop data : %d\n", data); // 取り出したデータの表示 
    state = pop(&x, &data);          // データの取り出し     
  }

  freeStack(&x);                     // スタックの解放(このプログラムではなくても問題)

  return(0);
}
