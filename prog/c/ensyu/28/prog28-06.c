#include <stdio.h>
#include <stdlib.h>

int gcm(int m, int n);

int main(int argc, char *argv[])
{
  int m, n;

  if (argc < 3) {
    fprintf(stderr, "引数に２つの整数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &m);
  sscanf(argv[2], "%d", &n);

  printf("%d\n", gcm(m, n));

  return(0);
}

int gcm(int m, int n)
{

}
