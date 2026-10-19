#include   <stdio.h>    //  ファイル操作・入出力関数用ヘッダファイル  
#include   <hamakou.h>  //  浜工情報技術科用ヘッダファイル            

main()
{
  int  x1, x2;

  x1 = 0x00FF00FF;    //  実験用データ１  
  x2 = 0x5555AAAA;    //  実験用データ２  

  putchar('\n');
  printf("     x1: %s = 0x%08X\n", int2bit(x1), x1);    //  x1の表示  
  printf("     x2: %s = 0x%08X\n", int2bit(x2), x2);    //  x2の表示  
  printf("\n--------------------------------------------------\n\n");
  printf("x1 & x2: %s = 0x%08X\n", int2bit(x1 & x2), x1 & x2);   //  AND演算子  
  printf("x1 | x2: %s = 0x%08X\n", int2bit(x1 | x2), x1 | x2);   //   OR演算子  
  printf("x1 ^ x2: %s = 0x%08X\n", int2bit(x1 ^ x2), x1 ^ x2);   //  XOR演算子  
  printf("\n--------------------------------------------------\n\n");
  printf("    ~x1: %s = 0x%08X\n", int2bit(~x1), ~x1);  //  NOT演算子  
  printf("    ~x2: %s = 0x%08X\n", int2bit(~x2), ~x2);  //  NOT演算子  
  putchar('\n');

  return(0);
}
