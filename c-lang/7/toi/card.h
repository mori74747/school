#include <stdio.h>

typedef struct{
    char mark;
    int num;
}Card;


void cardSet(Card card[]);
void cardPrint(Card card);
void cardShuffle(Card card[], int n);
int isOnePair(Card five_card[]);

/*
プログラムを作ること。
・cardSet()関数 ... 52枚のカードを用意する
・cardPrint()関数 ... 与えられた1枚のカードを表示する
・cardShuffle()関数 ... 与えられた52枚のカードを指定回数シャッフルする
*/