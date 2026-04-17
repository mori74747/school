/*
(x,y) = (2,4)
と表示される
*/
#include <stdio.h>

main()
{
  int x = 1;
  int y = 2;

  x += 1;
  y *= x;
  printf("(x,y)=(%d,%d)\n", x, y);

  return (0);
}
/*
xに1を足してx = 2になる
x=2になった状態でyに掛けるので、y = 4になる
よって
(x,y) = (2,4)
になる
*/
