#include <stdio.h>
#include <math.h>

main()
{
  double sum = 0.0;   // 級数の合計
  double d = 1.0;     // 分母
  double old_sum;     // 前の結果を保持
  double pi;          // 計算した円周率
  int sign = 1;       // 符号

  // 後判定型
  do{
    // 前の結果を保存
    old_sum = sum;

    sum += sign * (1.0 / d);

    // 次のカウンタの準備
    sign = -sign;
    d += 2.0;

    // 円周率を計算
    pi = 4.0 * sum;

    // 打切り誤差判定
  }while(fabs(sum - old_sum) / fabs(sum) >= 1.0e-7);

  printf("円周率 pi = %.10f\n", pi);

  return 0;
}
