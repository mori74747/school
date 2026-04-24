#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>

long long fib(int n);

int main(int argc, char *argv[])
{
  int i, n;
  long long f;
  double t1, t2;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <int_num>\n", argv[0]);
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  for (i = 1; i <= n; i++) {
    t1 = timecount("start");
    f = fib(i);
    t2 = timecount("stop");
    printf("%2d: %7.2f[s]  %ld\n", i, t2 - t1, f);
  }

  return(0);
}

long long fib(int n)
{
  if (n <= 2) {
    return(1);
  } else {
    return(fib(n - 1) + fib (n - 2));
  }
}
