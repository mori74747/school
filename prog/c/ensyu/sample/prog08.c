#include <stdio.h>
#include <hamakou.h>



main()
{
  int n;

  n = getint("Input n: ");
  printf("Ans = %d\n", sumConsInt(n));

  return(0);
}
