#include <stdio.h>

int x;
extern int y;
static int z;

int func1(void);
void func2(void);

main()
{
  z = func1();
  func2();
  printf("x = %d, y = %d, z = %d\n", x, y, z);  
}
