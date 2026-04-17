#include <stdio.h>
      
int  z;
void f( int x );
      
main()
{
  z = 5;
  f(z);
  printf("z = %d\n", z);

  return(0);
}

void f( int x )
{
  x = 2;
  z += x;

  return;
}
