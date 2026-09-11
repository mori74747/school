#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
#include "card.h"      // 「card.h」をカレントディレクトリからインクルードする

main()
{
  Card *card;  // Card型のポインタ変数
  int i;
  
  card = (Card*)malloc(sizeof(Card) * 10); // データ領域の確保
  if (card == NULL) {
    printf("メモリを確保できませんでした。\n");
    return(1);
  }
  
  for (i = 0; i < 10; i++) {
    card[i].mark = getcharacter("マークを入力してください：");
    card[i].num  = getint("カードの数字を入力してください：");
  }

  for (i = 0; i < 10; i++) {
    printf("%d枚目のカードは%cの%dです。\n", i+1,card[i].mark, card[i].num);
  }

  free(card);
  
  return(0);
}
