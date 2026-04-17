#include <stdio.h>
#include <hamakou.h>
#include <math.h>

main()
{
  double x;

  printf("|%3s","x");
  printf("|%14s","2√x");
  printf("|%14s","3√x");
  printf("|%12s","logx");
  printf("|%12s|\n","log10x");
  printf("-------------------------------------------------------\n");

  for(x = 0; x <= 100; x++){

    printf("|%3g",x);
    printf("|%12f", sqrt(x));
    printf("|%12f", pow(x,(double)1/3));
    printf("|%12f", log(x));
    printf("|%12f|\n", log10(x));

  }



  return(0);
}
