#include <stdio.h>
#include <hamakou.h>

main()
{
  int a;

  a = getint("整数 a = ");

  //---------------------- 好ましくないif文
  if (a > 0)
    printf("データは正の数です。\n");

  return(0);
}
