#include <stdio.h>

main()
{
  int i, total;  //  i    : 1, 2, 3, …, 10 を順に作る
                 //  total: 1 + 2 + 3 + … + 10 を格納

  total = 0;
  for (i = 1; i <= 10; i++) {  // iのカウントアップにはインクリメント演算子を使う
    total = total + i;         //  iが1〜10の間totalにiを加える
  }
  printf("1から 10までの和は %d です。\n",total);

  return(0);
}
