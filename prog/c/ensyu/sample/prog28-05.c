#include <stdio.h>
#include <stdlib.h>

long long stepCount(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "整数を引数に指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);
  printf("%ld\n", stepCount(n));

  return(0);
}

long long stepCount(int n)
{

}
