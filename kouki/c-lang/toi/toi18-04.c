#include <stdio.h>

main()
{
  int  source[10] = {1, 5, 8, 12, 2, 6, -6, 0, 4, 10};
  int  twice[10];
  int  i;

  for (i = 0; i < 10; i++) {
                   =              * 2;
  }
  for (i = 0; i < 10; i++) {
    printf("source[%d] = %d, twice[%d] = %d\n", i,               , i,               );
  }

  return(0);
}
