#include <stdio.h>

void input(int *p, int *q);

main()
{
  int x, y;


  input( &x, &y );
  printf("x: %d, y: %d\n", x, y);

  return(0);
}

void input(int *p, int *q)
{
  scanf("%d %d", p, q);

  return;
}
