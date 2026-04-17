#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>
                               // 「card.h」をカレントディレクトリからインクルードする

main()
{
  Card *card;  // Card型のポインタ変数
  int i;
  
  card = (     )malloc(                              ); // データ領域の確保
  if (card == NULL) {
    printf("メモリを確保できませんでした。\n");
    return(1);
  }
  
  for (i = 0; i < 10; i++) {
                           = getcharacter("マークを入力してください：");
                           = getint("カードの数字を入力してください：");
  }

  for (i = 0; i < 10; i++) {
    printf("%d枚目のカードは%cの%dです。\n", i,                   ,                    );
  }

  free(card);
  
  return(0);
}
