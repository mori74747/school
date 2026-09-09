#include <stdio.h>
#include <hamakou.h>

main()
{
  int x;

  x = getint("Input x: ");

  printf("x^2 = %d\n", x * x);

  return(0);
}
