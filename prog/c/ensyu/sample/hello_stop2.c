#include <stdio.h>

int main(int argc, char *argv[])
{
  int n;

  sscanf(argv[1], "%d", &n);
  if (n > 0) {
    printf("Hello world.\n");
    n--;
    sprintf(argv[1],"%d",n);
    main(argc, argv);
  }
  return(0);
}
