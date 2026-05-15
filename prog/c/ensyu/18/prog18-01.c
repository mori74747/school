#include<stdio.h>

typedef struct {
  int numerator;   // 分子
  int denominator; // 分母
} Fraction;

main()
{
  char buff[256];
  Fraction a, b, c;

  // 分数aをキーボードより入力する
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d/%d", &a.numerator, &a.denominator);

  // 入力した分数aを表示
  printf("a = %d/%d\n", a.numerator, a.denominator);

  // 分数bは2/3
  b.numerator   =  2;
  b.denominator =  3;

  // 分数bを表示
  printf("b = %d/%d\n", b.numerator, b.denominator);

  // c = a * b
  c.numerator   = a.numerator   * b.numerator;
  c.denominator = a.denominator * b.denominator;

  // 乗算結果である分数cの表示
  printf("a * b = %d/%d\n", c.numerator, c.denominator);

  return(0);
}
