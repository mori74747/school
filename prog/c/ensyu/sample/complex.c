#include <stdio.h>
#include <hamakou.h>

/* COMPLEX型の定義 */
typedef struct {
  double real;  /* 実数部 */
  double imag;  /* 虚数部 */
} COMPLEX;

/* 抽象データ型として扱うために必要になる関数群のプロトタイプ宣言 */
COMPLEX cAdd(COMPLEX x, COMPLEX y); /* x + y         */
COMPLEX cSub(COMPLEX x, COMPLEX y); /* x - y         */
COMPLEX cMul(COMPLEX x, COMPLEX y); /* x * y         */
COMPLEX cDiv(COMPLEX x, COMPLEX y); /* x / y         */
void    cPrint(COMPLEX x);          /* 複素数の表示  */
COMPLEX cSet(double a, double b);   /* a + bj の設定 */
double  cReal(COMPLEX x);           /* 実数部の取得  */
double  cImag(COMPLEX x);           /* 虚数部の取得  */

main()
{
  COMPLEX x, y, z;
  double a, b;

  a = getfloat("実数部：");  /* 実数部の入力     */
  b = getfloat("虚数部：");  /* 虚数部の入力     */
  x = cSet(a, b);            /* 複素数ｘの初期化 */

  a = getfloat("実数部：");  /* 実数部の入力     */
  b = getfloat("虚数部：");  /* 虚数部の入力     */
  y = cSet(a, b);            /* 複素数ｙの初期化 */

  printf("複素数 x = "); cPrint(x); putchar('\n');
  printf("複素数 y = "); cPrint(y); putchar('\n');
  printf("の四則演算\n");

  z = cAdd(x, y); /* 加算 */
  printf("x + y = "); cPrint(z); putchar('\n');
  z = cSub(x, y); /* 減算 */
  printf("x - y = "); cPrint(z); putchar('\n');
  z = cMul(x, y); /* 乗算 */
  printf("x * y = "); cPrint(z); putchar('\n');
  z = cDiv(x, y); /* 徐算 */
  printf("x / y = "); cPrint(z); putchar('\n');

  return(0);
}
