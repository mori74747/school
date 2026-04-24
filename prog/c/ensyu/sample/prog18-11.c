#include <stdio.h>
#include <stdlib.h> // abs()関数を使用するために必要

typedef struct {
  int numerator;   // 分子
  int denominator; // 分母
} Fraction;

Fraction getFraction(void);
Fraction frcCreate(int numerator, int denominator);
Fraction frcAdd(Fraction x, Fraction y);
Fraction frcSub(Fraction x, Fraction y);
Fraction frcMul(Fraction x, Fraction y);
Fraction frcDiv(Fraction x, Fraction y);
Fraction frcReduction(Fraction x);
int frcGetNumerator(Fraction x);
int frcGetDenominator(Fraction x);
void frcPrint(Fraction x);
void frcPrintOperation(char op, Fraction x, Fraction y);
int gcm(int m, int n);

main()
{
  Fraction a, b, c;
  int i;
  char op[] = "+-*/";

  // 2つの分数をキーボードより入力する
  printf("a: ");
  a = getFraction();
  printf("b: ");
  b = getFraction();

  if (frcGetDenominator(a) * frcGetDenominator(b) == 0) {
    printf("分母が0です\n");
  } else {
    // 分数a, bに対して、四則演算を実行する
    for (i = 0; op[i] != '\0'; i++) {
      frcPrintOperation(op[i], a, b); // 四則演算の結果表示
    }
    putchar('\n'); // 見やすくするために改行
  }

  return(0);
}

// 分数xと分数yに、2項演算(x op y)を実行した結果を表示する
//   [引　数] op   : 2項演算子（+, -, *, /)
//            x, y : 演算対象となる分数 
//   [表示例] 1/2 + 1/4 = 3/4
void frcPrintOperation(char op, Fraction x, Fraction y)
{
  Fraction a;

  switch (  ) {
  case '+':
    a =             ; break;
  case '-':
    a =             ; break;
  case '*':
    a =             ; break;
  case '/':
    a =             ; break;
  default:
    printf("%c: 演算子が不正です。\n", op);
    return;
  }
  a =                ;
  frcPrint(x); printf(" %c ", op); frcPrint(y); printf(" = "); frcPrint(a);
  putchar('\n');

  return;
}

// Fraction型で表される分数の分子の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分子の値
int frcGetNumerator(Fraction x)
{
}

// Fraction型で表される分数の分母の値を返す
// [引　数] Fraction型で表現される分数
// [戻り値] 分母の値
int frcGetDenominator(Fraction x)
{
}

// キーボードより、a/bの形で分数を入力する
//   [引　数] なし
//   [戻り値] Fraction型で表現される分数
Fraction getFraction(void)
{
  char buff[256];
  int n, d;

  fgets(buff, sizeof(buff), stdin);
  sscanf(                     );

  return(               );
}

// 分子と分母の値からFraction型で表される分数を返す
//   [引　数] numerator   : 分子の値
//            denominator : 分母の値
//   [戻り値] Fraction型で表現される分数
Fraction frcCreate(int numerator, int denominator)
{
}

// 分数xとyの加算結果を返す
//   [引　数] x, y : 加算対象となる分数 
//   [戻り値] x + y を計算して得られる分数
Fraction frcAdd(Fraction x, Fraction y)
{
}

// 分数xとyの減算結果を返す
//   [引　数] x, y : 減算対象となる分数 
//   [戻り値] x - y を計算して得られる分数
Fraction frcSub(Fraction x, Fraction y)
{
}

// 分数xとyの乗算結果を返す
//   [引　数] x, y : 乗算対象となる分数 
//   [戻り値] x * y を計算して得られる分数
Fraction frcMul(Fraction x, Fraction y)
{
}

// 分数xとyの除算結果を返す
//   [引　数] x, y : 除算対象となる分数 
//   [戻り値] x / y を計算して得られる分数
Fraction frcDiv(Fraction x, Fraction y)
{
}

// 分数xの既約分数を返す
//   [引　数] x : 約分対象となる分数 
//   [戻り値] xの既約分数
Fraction frcReduction(Fraction x)
{
}

// mとnの最大公約数を正数で返す
//   [引　数] m, n : 最大公約数を求める対象となる整数 
//   [戻り値] mとmの最大公約数
int gcm(int m, int n)
{
  int r;

  // 最大公約数を正数にするため、m,nの絶対値をとる
  m = abs(m);
  n = abs(n);

  r = m % n;
  while (r != 0) {
    m = n;
    n = r;
    r = m % n;
  }
  return(n);
}

// 分数xを a/b の形で表示する（分数の値が負になるとき、符号は分子につける）
//   [引　数] x : 表示する分数
void frcPrint(Fraction x)
{
  int n, d;
  
  n = frcGetNumerator(x);
  d = frcGetDenominator(x); 
  
  if (         ) {
    n = -abs(n);
    d = abs(d);
  } else {
    n = abs(n);
    d = abs(d);
  }
  if (n == 0 || d == 1) {
                                ;
  } else {
                                           ;
  }

  return;
}
