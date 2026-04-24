#include <stdio.h>
#include <hamakou.h>                // getint(), getfloat() を使用するために必要
main()
{
      max, a[100];       //使用する変数の宣言
      n, i;

    n = getint("Input n: ");        // データの個数ｎの入力

    if (n <= 0 || n > 100){         // データの個数は１～１００まで
        printf("データの数が正しくありません╲n");
    } else {
         ;                // データ ａ0, ａ1, …, ａn-1 の入力を行う反復構造
        while (){
            printf("a[%d] = ", i);
        = getfloat("");
        ;
        }

        max = a[0];                 // 最大値を求める反復構造
        i = 1;
        while (i < n) {
            if (a[i] > max) {
                max = a[i];
            }
            i = i + 1;
        }

        printf("max = %g\n", max);  // 最大値 max の表示
    }

    return (0);
}
