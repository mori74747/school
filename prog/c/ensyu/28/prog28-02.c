#include <stdio.h>
#include <stdlib.h>

long long fact(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に0以上の整数を指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%lld\n", fact(n));

  return(0);
}

long long fact(int n)
{
  // 基底条件
  if(n == 0 || n == 1){
    return (1);
  }else{
    return (n * fact(n-1));
  }
}
