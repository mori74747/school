#include <stdio.h>
#include <hamakou.h>

main()
{
  int a, b;

  a = getint("Input a: ");
  b = getint("Input b: ");

  printf("%d + %d = %d\n", a, b, a + b);

  return(0);
}
