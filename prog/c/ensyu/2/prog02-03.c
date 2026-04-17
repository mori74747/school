#include <stdio.h>
#include <hamakou.h>                // getint(), getfloat() を使用するために必要
main()
{
    float max, min, a[100];       //使用する変数の宣言
    int n, i;

    n = getint("Input n: ");        // データの個数ｎの入力

    if (n <= 0 || n > 100){         // データの個数は１～１００まで
        printf("データの数が正しくありません╲n");
    } else {
        i = 0 ;                // データ ａ0, ａ1, …, ａn-1 の入力を行う反復構造
        while ( i < n ){
            printf("a[%d] = ", i);
            a[i] = getfloat("");
            i = i + 1 ;
        }

        max = a[0];                 // 最大値を求める反復構造
        min = a[0];
        i = 1;
        while (i < n) {
            if (a[i] > max) {
                max = a[i];
            }else if(a[i] < min){
                min = a[i];
            }
            i = i + 1;
        }

        printf("max = %g min = %g\n", max, min);  // 最大値 max の表示
    }

    return (0);
}
