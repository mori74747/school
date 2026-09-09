#include <stdio.h>

double D(double a, double b, double c);

main()
{
  double a, b, c, d;
  char buff[256];

  printf("a b c: ");
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%lf %lf %lf", &a, &b, &c);

  d = D(a, b, c);
  if (d > 0) {
    printf("D = %g: 解2個\n", d);
  } else if (d < 0) {
    printf("D = %g: 解なし\n", d);
  } else {
    printf("D = %g: 重解\n", d);
  }

  return(0);
}

// [引  数] double型: a, b, c
// [戻り値] double型: 判別式D の解
double D(double a, double b, double c){

  return(b*b -4*a*c);
}