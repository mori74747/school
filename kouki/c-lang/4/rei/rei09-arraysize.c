#include <stdio.h>

main()
{
  int zaiseki[4][9] = {
    {41,40,40,40,40,41,41,42,0},   // １年生のデータ  
    {39,38,34,40,37,39,35,39,0},   // ２年生のデータ  
    {30,39,31,40,38,40,33,36,0},   // ３年生のデータ  
    {0,0,0,0,0,0,0,0,0}
  };

  printf("配列要素の大きさ(バイトサイズ)\n");
  printf("zaiseki[0][0]: %3d byte\n", sizeof(zaiseki[0][0]));
  printf("zaiseki[0]   : %3d byte\n", sizeof(zaiseki[0]));
  printf("zaiseki      : %3d byte\n", sizeof(zaiseki));

  return(0);
}
