#include <stdio.h>
      
#define PART1   7
#define PART2   5
/*
#define PART3   PART1 + PART2
あくまでも。defineによるマクロは置き換えが行われるだけ
置き換えた結果、四則演算の順序に基づき計算されるため、括弧が必要。

defineのマクロは定義された規定に沿って置き換えるだけなので、かけ算をするとき、
7 + 5 * 7 + 5
と置き換えられる。
C言語は四則演算の順序に基づいて計算を行うため、47となる。
意図通り、144を得るためには、括弧を付けて 7 + 5 を先に行う必要がある。
*/
#define PART3   ((PART1) + (PART2))


main()
{
  printf("%d * %d = %d\n", PART3, PART3, PART3 * PART3);
  return(0);
}
