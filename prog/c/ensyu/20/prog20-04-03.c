#include <stdio.h>
#include <hamakou.h>
#include <math.h>

// Complex型の定義 
typedef struct {
    double cmplx[2]; // cmplx[0]:実数部　 cmplx[1]:虚数部
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

// 回路の計算用に必要な関数群
Complex cImpedance(double L, double C, double R, double freq);
double  cSize(Complex Z);
double  cRad(Complex Z);

main()
{
    double L, C, R, freq;
    L = 200e-6;
    C = 0.127e-6;
    R = 25;
    freq = 100e3;

    Complex Z;
    double  Z_size, Z_rad;
    Z      = cImpedance(L, C, R, freq);
    Z_size = cSize(Z);
    Z_rad  = cRad(Z);

    printf("Z = "); cPrint(Z);        printf(" [Ω]\n");
    printf("Zの大きさ = %g", Z_size);  printf(" [Ω]\n");
    printf("Zの位相角 = %g", Z_rad);   printf(" [rad]\n");
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
        return;
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

    if(x_real != 0 || (x_real == 0 && x_imag == 0)){
        printf("%g", cReal(x));
    }

    if(x_imag < 0){

        if(x_real != 0){
            printf(" - ");
        }else{
            printf("-");
        }
        printf("%gj", fabs(x_imag));

    }else if(x_imag > 0){

        if(x_real != 0){
            printf(" + ");
        }
        printf("%gj", fabs(x_imag));
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
    x.cmplx[0] = a;
    x.cmplx[1] = b;

    return(x);
}

/*----------------------------------------
[引　数] : Complex型 x
[戻り値] : double型  x = a + bj の実数部a
[機　能] : x = a + bj (a,bは実数)のとき実数部のaを取り出す
----------------------------------------*/
double cReal(Complex x)
{
    return(x.cmplx[0]);
}

/*----------------------------------------
[引　数] : Complex型 x
[戻り値] : double型  x = a + bj の虚数部b
[機　能] : x = a + bj (a,bは実数)のとき実数部のbを取り出す
----------------------------------------*/
double cImag(Complex x)
{
    return(x.cmplx[1]);
}

/*----------------------------------------
[引　数] : Complex型  L, C, R （インダクタンス L, 静電容量 C, 抵抗 R）
[戻り値] : Complex型  Z
[機　能] : L, C, R の合成インピーダンスを返す
----------------------------------------*/
Complex cImpedance(double L, double C, double R, double freq){

    double rad = 2 * M_PI * freq;
    Complex one = cCreate(1.0,0.0);
    Complex Z1 = cCreate(0.0, -1.0 / (rad * C));
    Complex Z2 = cDiv(one, Z1);
    Complex Z3 = cDiv(one, cCreate(R, rad * L));

    Complex Z4 = cAdd(Z2, Z3);
    Complex Z  = cDiv(one, Z4);

    return(Z);
}

/*----------------------------------------
[引　数] : Complex型  Z (インピーダンス Z)
[戻り値] : double 型  Z_size (インピーダンスZの大きさ|Z|)
[機　能] : インピーダンスZの大きさ|Z|を返す。
----------------------------------------*/
double cSize(Complex Z){

    double Z_real = cReal(Z);
    double Z_imag = cImag(Z);

    return(sqrt(Z_real*Z_real + Z_imag*Z_imag));
}

/*----------------------------------------
[引　数] : Complex型  Z (インピーダンス Z)
[戻り値] : double 型  Z_rad (インピーダンスZの位相角Θ)
[機　能] : インピーダンスZの位相角Θを返す。
----------------------------------------*/
double cRad(Complex Z){

    double Z_real = cReal(Z);
    double Z_imag = cImag(Z);

    return(atan((Z_imag / Z_real)));
}