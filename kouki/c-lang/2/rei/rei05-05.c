#include <stdio.h>
#include <hamakou.h>

main()
{
  int a;

  a = getint("整数 a = ");

  if (a % 2 == 0) {
    printf("データは偶数です。\n");     // a が偶数 
  } else {
    printf("データは奇数です。\n");     // a が奇数 
  }
  return(0);
}
