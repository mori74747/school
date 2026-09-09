#include <stdio.h>
#include <hamakou.h>

main()
{
  int x, y, ans, i;

  x = getint("Input x: ");
  y = getint("Input y: ");

  ans = 1;
  for (i = 1; i <= y; i++) {
    ans = ans * x;
  }

  printf("%d^%d = %d\n",x, y, ans);

  return(0);
}
