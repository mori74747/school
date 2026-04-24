#include <stdio.h>
#include <stdlib.h>

long long fib(int n);
long long fib_tail(long long a, long long b, int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に正数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%d\n", fib(n));

  return(0);
}

// フィボナッチ数列の第n項の値を返す
long long fib(int n)
{
  return(fib_tail(  ,  ,  ));
}

long long fib_tail(long long a, long long b, int n)
{

}

