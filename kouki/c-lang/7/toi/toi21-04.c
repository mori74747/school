#include <stdio.h>
#include "card.h"
#include "hamakou.h"
main()
{
  int  n;
  char buff[256];

  printf("1 ~ 48枚目のトランプを選択\n");
  n = getint("");

  if(n < 1 || 48 < n){
    printf("有効なトランプを指定してください\n");
    return(1);
  }

  Card card[52];
  int i;

  cardSet(card);            // 52枚のカードをセットする 
  cardShuffle(card, 1000);  // 1000回シャッフルする     

  Card five_card[5];
  n--;

  for(i = 0; i < 5; i++){
    five_card[i] = card[n+i];
    printf("%d枚目 ", n+i+1);
    cardPrint(five_card[i]);
  }
  
  if(isOnePair(five_card)){
    printf("ワンペア！\n");
  }else{
    printf("ワンペアじゃない\n");
  }

  return(0);
}
