#include <stdio.h>
      
#define PART1   7
#define PART2   5
// #define PART3   PART1 + PART2
// あくまでも。defineによるマクロは置き換えが行われるだけ
// 置き換えた結果、四則演算の順序に基づき計算されるため、括弧が必要。
#define PART3   ((PART1) + (PART2))


main()
{
  printf("%d * %d = %d\n", PART3, PART3, PART3 * PART3);
  return(0);
}
