#include <stdio.h>

int total;  // 合計を格納する変数 
int count;  // カウンタ変数（グローバル）の宣言 

main()
{
  total = 0;
  count = 0;  // カウンタ変数（グローバル）の初期化 

  printf("count(global) = %d\n", count);
  {
    int count; // カウンタ変数（ローカル）の宣言   

    count = 1; // カウンタ変数（ローカル）の初期化 
    printf("count(local) = %d\n", count);
    while (count <= 10) {
        total += count;
        count++; // カウンタ変数（ローカル）の更新   
    }
    printf("count(local) = %d\n", count);
  }
  count++;   // カウンタ変数（グローバル）の更新 
  printf("count(global) = %d\n", count);
  printf("total(global) = %d\n", total);

  return(0);
}
