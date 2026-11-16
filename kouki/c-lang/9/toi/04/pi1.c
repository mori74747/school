#include <stdio.h>
#include <math.h>

main()
{
  int i;                // カウンタ変数
  int n = 10000000;     // 分割数
  double x, w, sum, pi;

  w = 1.0 / n;  // 事前に計算
  sum = 0.0;    // 初期化

  // 小さい値から順番に加算する
  for(i = n-1; i >= 0; i--){
    x = i * w;
    sum += sqrt(1.0 - x * x) * w;
  }

  pi = 4.0 * sum;

  printf("分割数 n = %d\n", n);
  printf("円周率 pi = %.10f\n", pi);

  return 0;
}
