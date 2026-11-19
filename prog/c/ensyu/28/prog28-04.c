#include <stdio.h>
#include <stdlib.h>

long long fib(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に正数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%lld\n", fib(n));

  return(0);
}

long long fib(int n)
{
  if(n == 0){
    return (0);
  }else if(n == 1){
    return (1);
  }else{
    // 前の候とその前の項を足す
    return (fib(n-1) + fib(n-2));
  }
}
