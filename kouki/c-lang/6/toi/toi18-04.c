#include <stdio.h>

main()
{
  int  source[10] = {1, 5, 8, 12, 2, 6, -6, 0, 4, 10};
  int  twice[10];
  int  i;

  for (i = 0; i < 10; i++) {
    *(twice + i) = *(source + i) * 2;
  }
  for (i = 0; i < 10; i++) {
    printf("source[%d] = %3d, twice[%d] = %3d\n", i, *(source + i), i, *(twice + i));
  }

  return(0);
}
