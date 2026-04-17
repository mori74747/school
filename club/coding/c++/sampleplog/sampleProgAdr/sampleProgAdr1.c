// アドレスで値を参照
#include <stdio.h>

int main () {
    // 変数を宣言する。
    int x = 5;
    printf("変更前 = %d\n",x);
    // intのポインタ型 adr を宣言し、x のアドレスを代入する。
    int* adr = &x;

    // intのポインタ型 adr を経由して変数 x の中身を変更する。
    *adr = 10;

    // x の中身を見る。
    printf ( "変更後 = %d\n", x );

    return ( 0 );
}