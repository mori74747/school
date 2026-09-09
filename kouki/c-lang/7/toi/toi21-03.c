#include <stdio.h>
#include "card.h"

main()
{
  Card card[52];
  int i;

  cardSet(card);            // 52枚のカードをセットする 
  cardShuffle(card, 1000);  // 1000回シャッフルする     

  for (i = 0; i < 52; i++) {
    cardPrint(card[i]);
  }

  return(0);
}
