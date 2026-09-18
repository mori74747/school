#include <stdio.h>
#include <string.h>
#include "hamakou.h"
#include "stack.h"
#include "queue.h"

main(){

  // A. 宣言・初期化
  int n;          // 入力される文字列の個数
  int i;          // カウンタ変数
  Queue str;      // 連結用
  Stack rev;      // 文字列の逆順並び替え用
  char moji[20];  // 入力される文字列

  // Queue, Stack の初期化
  initQueue(&str);
  initStack(&rev);

  n = getint("文字列の個数: ");

  // B. 各文字列の処理
  for(i = 0; i < n; i++){
    getstring("", moji);
    // 先頭文字で場合分け-処理
    switch(moji[0]){
      case ('+'):
        CatString(&str, );
        break;
      case ('-'):
        break;
    }
  }

  // C. 文字列の出力
  
  return (0);
}

/*---------------------------------------
［機 能］文字列をキューに連結させる
［引 数］str  ： 連結対象となるキュー
［　 　］moji ： もう片方の連結対象となる文字列
［戻り値］なし
---------------------------------------*/
CatString(Queue *str, char moji[]){

  return;
}