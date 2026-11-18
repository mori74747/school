#include <stdio.h>
#include <float.h>

main()
{
  printf("float:\n");
  printf("最大値 = %.6e\n", FLT_MAX);
  printf("最小値 = %.6e\n", -FLT_MAX);
  printf("最小の正の値 = %.6e\n", FLT_MIN);
  printf("計算機イプシロン = %.6e\n", FLT_EPSILON);
  printf("10進数の有効桁数 = %d\n\n", FLT_DIG);

  printf("double:\n");
  printf("最大値 = %.15e\n", DBL_MAX);
  printf("最小値 = %.15e\n", -DBL_MAX);
  printf("最小の正の値 = %.15e\n", DBL_MIN);
  printf("計算機イプシロン = %.15e\n", DBL_EPSILON);
  printf("10進数の有効桁数 = %d\n\n", DBL_DIG);

  printf("long double:\n");
  printf("最大値 = %.18Le\n", LDBL_MAX);
  printf("最小値 = %.18Le\n", -LDBL_MAX);
  printf("最小の正の値 = %.18Le\n", LDBL_MIN);
  printf("計算機イプシロン = %.18Le\n", LDBL_EPSILON);
  printf("10進数の有効桁数 = %d\n", LDBL_DIG);

  return (0);
}
