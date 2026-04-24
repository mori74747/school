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
  char buff[256];
  Fraction a, b, c;

  a = getFraction();   // 分数aをキーボードより入力する

  printf("a = ");
  frcPrint(a);         // 入力した分数aを表示
  putchar('\n');

  b = frcCreate(2, 3); // 分数bは2/3

  printf("b = ");
  frcPrint(b);         // 分数bを表示
  putchar('\n');

  c = frcMul(a, b);    // c = a * b

  printf("a * b = ");
  frcPrint(c);         // 乗算結果である分数cの表示
  putchar('\n');

  return(0);
}

// キーボードより、a/bの形で分数を入力する
// [引　数] msg[] : 入力時に表示するメッセージ
// [戻り値] Fraction型で表現される分数
Fraction getFraction(void)
{
}

// 分子と分母の値からFraction型で表される分数を返す
// [引　数] numerator   : 分子の値
//          denominator : 分母の値
// [戻り値] Fraction型で表現される分数
Fraction frcCreate(int numerator, int denominator)
{
}

// 分数xを a/b の形で表示する
// [引　数] x : 表示する分数
void frcPrint(Fraction x)
{
}

// 分数xとyの乗算結果を返す
// [引　数] x, y : 乗算対象となる分数
// [戻り値] x * y を計算して得られる分数
Fraction frcMul(Fraction x, Fraction y)
{
}
