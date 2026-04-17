#include <stdio.h>
#include <stdlib.h>
      
#define FOREVER    1
#define STOP      17
      
void f( void );

main()
{
  while (FOREVER) {
    f();
  }
}

void f( void )
{
  static int cnt = 0;

  printf("cnt = %d\n", ++cnt);
  if (cnt == STOP) {
    exit(0);
  }
}
