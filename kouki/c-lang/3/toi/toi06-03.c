#include <stdio.h>
#include <hamakou.h>
#include <math.h>

main()
{
  double x;

  printf("|   2x   |   3x   |   logx   |   log10x   |\n");
  for(x = 0; x <= 100; x++){

    printf("|%9g", sqrt(x));
    printf("|%9g", pow(x,(double)1/3));
    printf("|%9g", log(x));
    printf("|%10g|\n", log10(x));

  }



  return(0);
}
