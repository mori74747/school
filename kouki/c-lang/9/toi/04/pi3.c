#include <stdio.h>
#include <math.h>

main()
{
  double sum = 0.0;   // 級数の合計
  double loss = 0.0;  // 積み残し(情報落ちで失われる下位桁)
  double d = 1.0;     // 分母
  double term;        // 今回加える項
  double work, t;     // 積み残し処理用
  double pi;          // 計算した円周率
  int sign = 1;       // 符号

  // 後判定型
  do{
    // 今回の項
    term = sign / d;

    // 積み残し処理
    work = sum;
    t = term + loss;
    sum = sum + t;
    loss = t - (sum - work);

    // 次のカウンタの準備
    sign = -sign;
    d += 2.0;

    // 打切り誤差判定
  }while(fabs(term) / fabs(sum) >= 1.0e-7);

  // 円周率を計算
  pi = 4.0 * sum;

  printf("円周率 pi = %.10f\n", pi);

  return (0);
}