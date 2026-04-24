#include <stdio.h>
#include <hamakou.h>

// Complex型の定義 
typedef struct {
  double real;  // 実数部 
  double imag;  // 虚数部 
} Complex;

// 抽象データ型として扱うために必要になる関数群
Complex cAdd(Complex x, Complex y);   // x + y         
Complex cSub(Complex x, Complex y);   // x - y         
Complex cMul(Complex x, Complex y);   // x * y         
Complex cDiv(Complex x, Complex y);   // x / y         
void    cPrint(Complex x);            // 複素数の表示  
Complex cCreate(double a, double b);  // a + bj の設定 
double  cReal(Complex x);             // 実数部の取得  
double  cImag(Complex x);             // 虚数部の取得  

main()
{
  Complex x, y, z;
  double a, b;

  printf("x <- 実数部 虚数部："); // 実数部と虚数部の入力
  scanf("%lg %lg", &a, &b);
  x = cCreate(a, b);              // 複素数ｘの初期化

  printf("y <- 実数部 虚数部："); // 実数部と虚数部の入力
  scanf("%lg %lg", &a, &b);
  y = cCreate(a, b);              // 複素数ｙの初期化

  putchar('\n');
  printf("複素数 x = "); cPrint(x); putchar('\n');
  printf("複素数 y = "); cPrint(y); putchar('\n');
  printf("の四則演算\n");

  z = cAdd(x, y); // 加算 
  printf("x + y = "); cPrint(z); putchar('\n');
  z = cSub(x, y); // 減算 
  printf("x - y = "); cPrint(z); putchar('\n');
  z = cMul(x, y); // 乗算 
  printf("x * y = "); cPrint(z); putchar('\n');
  z = cDiv(x, y); // 徐算 
  printf("x / y = "); cPrint(z); putchar('\n');

  return(0);
}

Complex cAdd(Complex x, Complex y)
{
}

Complex cSub(Complex x, Complex y)
{
}

Complex cMul(Complex x, Complex y)
{
}

Complex cDiv(Complex x, Complex y)
{
}

void cPrint(Complex x)
{
}

Complex cCreate(double a, double b)
{
}

double cReal(Complex x)
{
}

double cImag(Complex x)
{
}
