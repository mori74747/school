#include <stdio.h>
      
#define SIZE    10;
#define FUDGE   SIZE - 2;

main()
{
  int size;   //  実際に用いるサイズ  

  size = FUDGE;
  printf("サイズは %d\n", size);

  return(0);
}
