#include <stdio.h>
#include <math.h>

main()
{
  long i;               // カウンタ変数
  long n = 10000000;     // 分割数
  double x, y, w, sum, pi;
  double loss, work, d; // 積み残し処理用(情報落ちの補正)

  w = 1.0 / n;  // 事前に計算 (各項には掛けず、最後に1回だけ掛ける)
  sum = 0.0;    // 初期化
  loss = 0.0;   // 積み残しの初期化

  // 小さい値から順番に加算する
  for(i = n-1; i >= 0; i--){
    x = (double)i / n;        // x = i*w と掛け算せず、割り算で直接求める
    y = (double)(n - i) / n;  // 1-x を引き算せずに求める(桁落ち防止)

    d = sqrt(y * (1.0 + x));  // sqrt(1-x*x) = sqrt((1-x)(1+x)) (桁落ち防止)

    // 積み残し処理(情報落ちの補正)
    work = sum;
    d = d + loss;
    sum = sum + d;
    loss = d - (sum - work);
  }

  pi = 4.0 * sum * w;

  printf("分割数 n = %ld\n", n);
  printf("円周率 pi = %.10f\n", pi);

  return (0);
}

/*
  分割数nの考察

  誤差が約 2/n で、6桁には n が約400万以上必要であるため、余裕を見て1000万に設定した。
 */