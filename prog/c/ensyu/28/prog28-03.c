#include <stdio.h>
#include <stdlib.h>

double ipow(double a, int x);

int main(int argc, char *argv[])
{
  double a;
  int x;

  if (argc < 3) {
    fprintf(stderr, "第1引数に実数を、第2引数に整数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%lf", &a);
  sscanf(argv[2], "%d", &x);

  printf("%g\n", ipow(a, x));

  return(0);
}

double ipow(double a, int x)
{
  if(x == 0){
    return (1);
  }else if(x > 0){
    // aを掛けて再帰
    return (a * ipow(a, x-1));
  }else if(x < 0){
    // 1/aを掛けて再帰
    return ((1/a) * ipow(a, x+1));
  }
}
