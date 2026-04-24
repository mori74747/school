#include <stdio.h>
#include <stdlib.h>

long double cntHanoi(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <number of disk>\n", argv[0]);
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%d枚を移動する手順: %.0Lf回\n", n, cntHanoi(n));

  return(0);
}

long double cntHanoi(int n)
{
  if(     ) {
    return(                       );
  } else {
    return(0);
  }
}
