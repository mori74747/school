#include <stdio.h>
#include <limits.h>

main()
{
  printf("char:\n");
  printf("最大値 = %d\n", CHAR_MAX);
  printf("最小値 = %d\n\n", CHAR_MIN);

  printf("int:\n");
  printf("最大値 = %d\n", INT_MAX);
  printf("最小値 = %d\n\n", INT_MIN);

  printf("long:\n");
  printf("最大値 = %ld\n", LONG_MAX);
  printf("最小値 = %ld\n\n", LONG_MIN);

  printf("long long:\n");
  printf("最大値 = %lld\n", LLONG_MAX);
  printf("最小値 = %lld\n", LLONG_MIN);

  return (0);
}
