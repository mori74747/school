#include <stdio.h>
#include <hamakou.h>
#include <math.h>

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

/*----------------------------------------
[引　数] : Complex型 x, y
[戻り値] : Complex型 x+yの解
[機　能] : x = a + bj, y = c + dj (a,b,c,d は実数)のときx+yを計算
----------------------------------------*/
Complex cAdd(Complex x, Complex y)
{
    double real_x = cReal(x);
    double imag_x = cImag(x);
    double real_y = cReal(y);
    double imag_y = cImag(y);
    
    // x + y = (a + bj) + (c + dj) = (a + c) + (b + d)j
    return(cCreate(real_x + real_y, imag_x + imag_y));

}

/*----------------------------------------
[引　数] : Complex型 x, y
[戻り値] : Complex型 x-yの解
[機　能] : x = a + bj, y = c + dj (a,b,c,d は実数)のときx-yを計算
----------------------------------------*/
Complex cSub(Complex x, Complex y)
{
    Complex minus_y;
    minus_y = cCreate(-cReal(y), -cImag(y));
    
    // x - y = (a + bj) - (c + dj) = (a - c) + (b - d)j
    return(cAdd(x, minus_y));
}

/*----------------------------------------
[引　数] : Complex型 x, y
[戻り値] : Complex型 x*yの解
[機　能] : x = a + bj, y = c + dj (a,b,c,d は実数)のときx*yを計算
----------------------------------------*/
Complex cMul(Complex x, Complex y)
{
    double real_x = cReal(x);
    double imag_x = cImag(x);
    double real_y = cReal(y);
    double imag_y = cImag(y);
    
    // x * y = (a + bj)(c + dj) = (ac - bd) + (bc + ad)j
    return(cCreate((real_x*real_y - imag_x*imag_y), (imag_x*real_y + real_x*imag_y)));
}

/*----------------------------------------
[引　数] : Complex型 x, y
[戻り値] : Complex型 x/yの解
[機　能] : x = a + bj, y = c + dj (a,b,c,d は実数)のときx/yを計算
----------------------------------------*/
Complex cDiv(Complex x, Complex y)
{
    double real_x = cReal(x);
    double imag_x = cImag(x);
    double real_y = cReal(y);
    double imag_y = cImag(y);
    
    // 分母
    double denominator = real_y*real_y + imag_y*imag_y;

    if(denominator == 0){
        printf("---0除算エラー---\n");
        return(cCreate(NAN, NAN));
    }
    // 虚数部だけminusなyを作る
    Complex imag_minus_y;
    imag_minus_y = cCreate(real_y, -imag_y);

    // 分子
    Complex numerator = cMul(x, imag_minus_y);

    // x ¹ y = (a + bj) / (c + dj) = (a + bj)(c - dj) / (c + dj)(c - dj) 
    //       = (ac + bd) + (bc - ad)j / (c^2 + d^2)
    return(cCreate(cReal(numerator)/denominator, cImag(numerator)/denominator));
}

/*----------------------------------------
[引　数] : Complex型 x
[戻り値] : なし
[機　能] : 複素数xを a + bj のように表示
----------------------------------------*/
void cPrint(Complex x)
{
    double x_real = cReal(x);
    double x_imag = cImag(x);
    double plus_x_imag = fabs(x_imag);

    if(x_real != 0 || (x_real == 0 && x_imag == 0)){
        printf("%g", cReal(x));
    }

    if(x_imag < 0){

        if(x_real != 0){
            printf(" - ");
        }else{
            printf("-");
        }
        if(plus_x_imag != 1){
            printf("%g", plus_x_imag);
        }
        printf("j");

    }else if(x_imag > 0){

        if(x_real != 0){
            printf(" + ");
        }
        if(plus_x_imag != 1){
            printf("%g", plus_x_imag);
        }
        printf("j");
    }
    return;
}

/*----------------------------------------
[引　数] : double型  a, b
[戻り値] : Complex型 a + bj の虚数x
[機　能] : 実数a,bから複素数 a + bj を初期化(生成)する。
----------------------------------------*/
Complex cCreate(double a, double b)
{
    Complex x;
    x.real = a;
    x.imag = b;

    return(x);
}

/*----------------------------------------
[引　数] : Complex型 x
[戻り値] : double型  x = a + bj の実数部a
[機　能] : x = a + bj (a,bは実数)のとき実数部のaを取り出す
----------------------------------------*/
double cReal(Complex x)
{
    return(x.real);
}

/*----------------------------------------
[引　数] : Complex型 x
[戻り値] : double型  x = a + bj の虚数部b
[機　能] : x = a + bj (a,bは実数)のとき実数部のbを取り出す
----------------------------------------*/
double cImag(Complex x)
{
    return(x.imag);
}
