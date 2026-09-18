#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*-----操作関数-----*/

/*---------------------------------------
［機 能］     キューを初期化し、空の状態にする
［引 数］q ： 初期化するキューのポインタ
---------------------------------------*/
void initQueue(Queue *q){
  // 先頭と末尾を初期化
  q->head = QUEUE_SIZE;
  q->tail = QUEUE_SIZE;
  return;
}

/*---------------------------------------
［機 能］キューにデータを格納する
［引 数］q    ： データの格納対象となるキュー
［　 　］data ： キューqへ格納するデータ
［戻り値］正常終了＝１，キューが満杯＝０
---------------------------------------*/
int  enQueue(Queue *q, int data){
  if((q->tail+1) % QUEUE_SIZE == q->head){
    return (0);
  }else{
    // 上限を超えたか判定
    q->tail = (q->tail+1) % QUEUE_SIZE;
    // 格納
    q->storage[q->tail] = data;

    return (1);
  }
}

/*---------------------------------------
［機 能］キューからデータを取り出す
［引 数］q    ： データの取り出し対象となるキュー
［　 　］data ： キューqから取り出したデータ
［戻り値］正常終了＝１，キューが空＝０
---------------------------------------*/
int  deQueue(Queue *q, int *data){
  if(q->head == q->tail){
    return (0);
  }else{
    // 上限を超えたか判定
    q->head = (q->head+1) % QUEUE_SIZE;
    // 取り出し
    *data = q->storage[q->head];

    return (1);
  }
}