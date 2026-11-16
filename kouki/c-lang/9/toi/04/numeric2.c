
#include <stdio.h>
#include <float.h>

main()
{
  printf("float:\n");
  printf("最大値 = %e\n", FLT_MAX);
  printf("最小値 = %e\n", -FLT_MAX);
  printf("最小の正の値 = %e\n", FLT_MIN);
  printf("計算機イプシロン = %e\n", FLT_EPSILON);
  printf("10進数の有効桁数 = %d\n\n", FLT_DIG);

  printf("double:\n");
  printf("最大値 = %e\n", DBL_MAX);
  printf("最小値 = %e\n", -DBL_MAX);
  printf("最小の正の値 = %e\n", DBL_MIN);
  printf("計算機イプシロン = %e\n", DBL_EPSILON);
  printf("10進数の有効桁数 = %d\n\n", DBL_DIG);

  printf("long double:\n");
  printf("最大値 = %Le\n", LDBL_MAX);
  printf("最小値 = %Le\n", -LDBL_MAX);
  printf("最小の正の値 = %Le\n", LDBL_MIN);
  printf("計算機イプシロン = %Le\n", LDBL_EPSILON);
  printf("10進数の有効桁数 = %d\n", LDBL_DIG);

  return (0);
}
