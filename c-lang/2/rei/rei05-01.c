#include <stdio.h>
#include <hamakou.h>

main()
{
  int a;

  a = getint("整数を入力してください。");

  if (a > 0) {
     printf("変数a は 0より大きい。\n");
  }
  if (a < 0) {
    printf("変数a は 0より小さい。\n");
  }
  return(0);
}
