// 配列の実態
#include <stdio.h>

int main () {
    // 配列 array を宣言し、数字を格納する。
    int array[8] = { 2, 0, 0, 8, 0, 4, 2, 9 };

    // 従来のアクセス
    for ( int i = 0; i < 8; i++ ) {
        printf ( "%d ", array[i] );
    }
    
    printf ( "\n" );

    // ポインタ型を使ってアクセス
    for ( int adrPlus = 0; adrPlus < 8; adrPlus++ ) {
        int ans = * ( array + adrPlus );

        printf ( "%d ", ans );
    }
    printf("\n");

    return ( 0 );
}