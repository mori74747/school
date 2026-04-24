#include <stdio.h>
#include <hamakou.h>

// 2つの整数 a, b の四則演算結果と、a を b で割った余りを表示する
main()
{
  int a, b;

  a = getint("Input a: ");
  b = getint("Input b: ");

  printf("%d + %d = %d\n", a, b, a + b);
  printf("%d - %d = %d\n", a, b, a - b);
  printf("%d * %d = %d\n", a, b, a * b);
  printf("%d / %d = %d\n", a, b, a / b);
  printf("%d mod %d = %d\n", a, b, a % b);

  return(0);
}
