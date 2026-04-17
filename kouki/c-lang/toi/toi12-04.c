#include <stdio.h>



main()
{
  double a, b, c, d;
  char buff[256];

  printf("a b c: ");
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%lf %lf %lf", &a, &b, &c);

  d = D(a, b, c);
  if (     ) {
    printf("D = %g: 解2個\n", d);
  } else if (     ) {
    printf("D = %g: 解なし\n", d);
  } else {
    printf("D = %g: 重解\n", d);
  }

  return(0);
}
