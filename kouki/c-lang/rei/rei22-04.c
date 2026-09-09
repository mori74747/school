#include <stdio.h>

main()
{
  int n = 0;

  while (n == 0) {
    printf("n = ");
    fscanf(stdin, "%d", &n);
  }
}
