#include <stdio.h>
#include <hamakou.h>

main()
{
  int x,y;

  x = getint("整数 x = ");
  y = getint("整数 y = ");

  if (x >= 0 && x <= 100) {
    printf("x は 0以上 100以下の整数\n");
  }
  if (y <= 0 || y >= 100) {
    printf("y は 0以下か 100以上の整数\n");
  }
  if (!(x > y)) {
    printf("x は y より大きくない\n");
  }
  return(0);
}
