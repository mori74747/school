#include <stdio.h>

extern int x;
extern int y;

int func1()
{
  x = 1;
  y = 2;
  return(-1);
}
