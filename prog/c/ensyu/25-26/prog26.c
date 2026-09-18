#include <stdio.h>
#include "hamakou.h"
#include "stack.h"
#include "queue.h"

void CatString(Queue *str, char moji[]);
void RevString(Stack *rev, char moji[]);
void ShowQueue(Queue *q);

main(){

  // A. 宣言・初期化
  int n;            // 入力される文字列の個数
  int i;            // カウンタ変数
  Queue str;        // 連結用
  Stack rev;        // 文字列の逆順並び替え用
  char s[20];       // 入力される文字列
  char *moji = s+1; // 先頭を排除した文字列

  // Queue, Stack の初期化
  initQueue(&str);
  initStack(&rev);

  n = getint("文字列の個数: ");

  // B. 各文字列の処理
  for(i = 0; i < n; i++){
    getstring("", s);
    // 先頭文字で場合分け-処理
    switch(s[0]){
      case ('+'):
        CatString(&str, moji);
        break;
      case ('-'):
        RevString(&rev, moji);
        CatString(&str, moji);
        break;
    }
  }

  // C. 文字列の出力
  ShowQueue(&str);
  return (0);
}

/*---------------------------------------
［機 能］文字列をキューに連結させる
［引 数］str  ： 連結対象となるキュー
［　 　］moji ： もう片方の連結対象となる文字列
［戻り値］なし
---------------------------------------*/
void CatString(Queue *str, char moji[]){
  int i;    // カウンタ変数

  // 文字列を全てキューに入れて連結させる
  for(i = 0; moji[i] != '\0'; i++){
    enQueue(str, moji[i]);
  }
  return;
}

/*---------------------------------------
［機 能］文字列を逆順にする
［引 数］rev  ： 逆順に必要なスタック
［　 　］moji ： 逆順にする文字列
［戻り値］なし
---------------------------------------*/
void RevString(Stack *rev, char moji[]){
  int i;  // カウンタ変数

  // 文字列を全てスタックに入れる
  for(i = 0; moji[i] != '\0'; i++){
    push(rev, moji[i]);
  }
  // 文字列を全てスタックから取り出す
  i = 0;
  while(pop(rev, &moji[i])){
    i++;
  }
  return;
}

/*---------------------------------------
［機 能］キューに格納された文字列の内容を表示する
［引 数］q    ： 表示するキュー
［戻り値］なし
---------------------------------------*/
void ShowQueue(Queue *q){
  char data;   // 取り出した内容

  // 文字列を全てキューから取り出す-出力
  while(deQueue(q, &data)){
    printf("%c", data);
  }
  putchar('\n');

  return;
}