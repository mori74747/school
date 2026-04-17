// アドレス計算と型の違い
#include <stdio.h>

int main () {
    // 4 つのポインタ型を用意する。
    // しかし、それぞれ別の型である。

    // char型（ 1 バイト ）
    char* adrChar = 0;

    // int型（ 4 バイト ）
    int* adrInt = 0;

    // long long型（ 8 バイト ）
    long long* adrLL = 0;

    // double型（ 8 バイト ）
    double* adrDbl = 0;

    // 1 を足したときの違いを見る。
    printf ( "adrChar + 1 = %llu\n", ( unsigned long long )( adrChar + 1 ) );
    printf ( "adrInt + 1 = %llu\n", ( unsigned long long )( adrInt + 1 ) );
    printf ( "adrLL + 1 = %llu\n", ( unsigned long long )( adrLL + 1 ) );
    printf ( "adrDbl + 1 = %llu\n", ( unsigned long long )( adrDbl + 1 ) );

    return ( 0 );
}