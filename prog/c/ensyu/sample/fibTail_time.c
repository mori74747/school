#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>

long long fib(     ,      ,      );

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
    f = fib( ,  ,  );
    t2 = timecount("stop");
    printf("%2d: %7.2f[s]  %ld\n", i, t2 - t1, f);
  }

  return(0);
}

long long fib(     ,      ,      )
{
  if (n <= 2) {
    return( );
  } else {
    return(fib(     ,     ,     ));
  }
}
