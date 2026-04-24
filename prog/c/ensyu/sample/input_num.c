#include <stdio.h>
#include <hamako.h>

main()
{
  int i;    // 整数
  double x; // 倍精度実数
  float y;  // 単精度実数

  // 整数を浜工関数 getint() で入力。long や long long 型の整数は扱えない
  i = getint("Input int_num: "); // 入力時にメッセージを表示できる
  printf("i(整数) = %d\n\n", i);

  // getfloat() は入力した実数を倍精度実数として扱う
  x = getfloat("Input double_num: ");
  // 倍精度実数の精度は、有効桁数は約15桁
  printf("x(倍精度実数) = %.16lf\n\n", x);

  // 単精度実数を浜工関数 getfloat() で入力
  y = getfloat("Input float_num: ");
  // 単精度実数の精度は、有効桁数は約6桁
  printf("y(単精度実数) = %.16f\n\n", y);

  return(0);
}
