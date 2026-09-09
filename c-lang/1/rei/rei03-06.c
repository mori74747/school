#include <stdio.h>

main()
{
  long long a;
  float b;

  a = 1234567890LL;
  b = a;

  printf("a = %lld\n", a);  //  変数 a の表示
  printf("b = %f\n", b);    //  変数 b の表示

  return(0);
}
