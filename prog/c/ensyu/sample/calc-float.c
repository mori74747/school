#include <stdio.h>
#include <hamakou.h>

// 2つの実数 a, b の四則演算結果を表示する
main()
{
  float a, b;

  a = getfloat("Input a: ");
  b = getfloat("Input b: ");

  printf("%g + %g = %g\n", a, b, a + b);
  printf("%g - %g = %g\n", a, b, a - b);
  printf("%g * %g = %g\n", a, b, a * b);
  printf("%g / %g = %g\n", a, b, a / b);

  return(0);
}
