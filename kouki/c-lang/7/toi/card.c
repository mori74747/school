#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

// 52枚のカードを用意する
void cardSet(Card card[])
{
  int i;

  for (i = 0; i < 52; i++) {
    card[i].num = i / 4 + 1;
    switch (i % 4) {
      case 0: card[i].mark = 'H'; break;
      case 1: card[i].mark = 'D'; break;
      case 2: card[i].mark = 'S'; break;
      case 3: card[i].mark = 'C'; break;
    }
  }

  return;
}

// 与えられた1枚のカードを表示する
void cardPrint(Card card)
{
  printf("%c:%2d\n", card.mark, card.num);
  return;
}

//  配列 card[]を n回シャッフルする
//  1回のシャッフルは、2枚のカードの交換により行う
void cardShuffle(Card card[], int n)
{
  int i, j, k;               //  j,k: 発生した乱数を格納  
  Card temp;

  srand(time(NULL));         //  乱数の初期化 
  for (i = 0; i < n; i++) {
    j = rand() % 52;         //  0〜51の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
    k = rand() % 52;         //  0〜51の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
    temp    = card[j];       // --+                         
    card[j] = card[k];       //   |- 2枚のカードを交換      
    card[k] = temp;          // --+                         
  }

  return;
}

/*----------------------------------------------------
[引  数] five_card[]: 5枚のカードを格納した配列
[戻り値] ワンペアがある場合 ... 1
[      ] ワンペアがない場合 ... 0
----------------------------------------------------*/
int isOnePair(Card five_card[]){
  int i, j;         // カウンタ変数
  int count = 0;    // 一致しているカードの数

  for(i = 0; i < 5; i++){
    for(j = i+1; j < 5; j++){
      if(five_card[i].num == five_card[j].num){
        count++;
      }
    }
  }
  if(count == 1){
    return(1);
  }else{
    return(0);
  }
}