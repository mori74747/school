#include<stdio.h>

typedef struct {
  int numerator;   // 分子
  int denominator; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int numerator, int denominator);
Fraction frcMul(Fraction x, Fraction y);
void frcPrint(Fraction x);

main()
{
  Fraction a, b, c;

  a =              ;   // 分数aをキーボードより入力する

  printf("a = ");
             ;         // 入力した分数aを表示
  putchar('\n');

  b =                ; // 分数bは2/3

  printf("b = ");
             ;         // 分数bを表示
  putchar('\n');

  c =             ;    // c = a * b

  printf("a * b = ");
             ;         // 乗算結果である分数cの表示
  putchar('\n');

  return(0);
}
