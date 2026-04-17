#include <stdio.h>

void  increment(int *p);

main()
{
  int count = 0;

  while (count < 10) {
    increment(&count);
    printf("count = %d\n", count);
  }

  return(0);
}

void increment(int *p)
{
  (*p)++;

  return;
}
