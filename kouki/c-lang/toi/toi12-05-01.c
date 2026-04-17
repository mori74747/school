#include <stdio.h>
#include <hamakou.h>



main()
{
  int n, count;

  n = getint("nを入力して下さい: ");

  printf("\n%d から生成されるから生成される「霰」\n\n", n);

  count = hailstones(n);

  printf("\n合計 %d 個\n", count);


  return(0);
}
