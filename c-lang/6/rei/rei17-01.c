#include <stdio.h>
#include <hamakou.h>

void swap(int x, int y);

main()
{
  int x, y;

  x = getint("x: ");
  y = getint("y: ");
  printf("交換前: x = %d, y = %d\n", x, y);

  swap(x, y);

  printf("交換後: x = %d, y = %d\n", x, y);

  return(0);
}

void swap(int x, int y)
{
  int work;   // 作業用変数 

  work = x;   // -+                
  x = y;      //  |- 入れ換え処理  
  y = work;   // -+                

  return;
}
