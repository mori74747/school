#include <stdio.h>

int y;
static int z;

void func2()
{
  z = 100;
  printf("func2: y = %d, z = %d\n", y, z);
  return;
}
