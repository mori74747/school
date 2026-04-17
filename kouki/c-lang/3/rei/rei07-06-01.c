#include <stdio.h>

main()
{
  int a[10], i;
  
  i = 0;
  while (1) {
    a[i] = i;
    printf("a[%d] = %d\n", i, a[i]);
    i = i + 1000;
  }
  
  return(0);
}
