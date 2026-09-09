#include <stdio.h>

main()
{
  int i, total;  //  i    : 1, 2, 3, …, 10 を順に作る
                 //  total: 1 + 2 + 3 + … + 10 を格納

  total = 0;
  i = 1;
  while(i <= 10) {       //  iが1〜10の間totalにiを加える
    total = total + i;   //  totalにはこれまでの合計が入る
    i = i + 1;           //  次に加える値を更新
  }
  printf("1から 10までの和は %d です。\n",total);

  return(0);
}
