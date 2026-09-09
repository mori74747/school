#include <stdio.h>

main()
{
  int i, j, x, y;

  i = j = 5;

  x = i++;  //  x = i を実行後、i++ を実行
  y = ++j;  //  ++j を実行後、 y = jを実行

  printf("i = %d\n",i);  //  i, j はともに 6 になる
  printf("j = %d\n",j);
  printf("x = %d\n",x);  //  x は 5、y は 6 になる
  printf("y = %d\n",y);

  return(0);
}
