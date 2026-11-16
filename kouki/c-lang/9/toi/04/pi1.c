#include <stdio.h>
#include <math.h>

main()
{
  int i;
  int n = 10000000;
  double x, w, sum, pi;

  w = 1.0 / n;
  sum = 0.0;

  /* 小さい値から順番に加算する */
  for (i = n - 1; i >= 0; i--) {
      x = i * w;
      sum += sqrt(1.0 - x * x) * w;
  }

  pi = 4.0 * sum;

  printf("分割数 n = %d\n", n);
  printf("円周率 pi = %.10f\n", pi);

  return 0;
}
