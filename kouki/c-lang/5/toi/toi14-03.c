#include <stdio.h>

int threeTimes(void);

main()
{
  int i;

  for (i = 1; i <= 10; i++) {
    printf("%2d回目: %d\n", i, threeTimes());
  }

  return(0);
}

// ifは使わない
// ただし、初めて呼び出された時に返す値は、1とする

// [引  数] なし
// [戻り値] 1を初期値として関数呼び出すごとに*3をする。
int threeTimes(void)
{
  static int mul = 1;
  int back_mul = mul;
  mul *= 3;
  return(back_mul);
}
