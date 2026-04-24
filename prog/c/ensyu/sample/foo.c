#include <stdio.h>

int foo(int x);

main()
{
  int x = 500, y;

  y = foo(x);
  printf("x: %d, y: %d\n", x, y);

  return(0);
}

int foo(int x) // 常に100を返す関数
{
  x = 100;

  return(x);
}
