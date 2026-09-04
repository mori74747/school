#include <stdio.h>
#include <hamakou.h>
#include "stack.h"

main()
{
    Stack x;
    int data1, data2;

    initStack(&x);                   // スタックの初期化 

    data1 = getint("push data1 : "); // データ１を入力       
    data2 = getint("push data2 : "); // データ２を入力       

    printf("\n交換前 - data1: %d, data2: %d\n", data1, data2);

    push(&x, data1);  // 入力データ１と２をスタックへ格納　 
    push(&x, data2);  // (データ格納後のスタックの状態を意識しておくこと)

    pop(&x, &data1);  // データ１と２をスタックから取り出す 
    pop(&x, &data2);  // (スタックの状態からデータの取り出し順序を考える)

    printf("交換後 - data1: %d, data2: %d\n\n", data1, data2);

    return(0);
}
