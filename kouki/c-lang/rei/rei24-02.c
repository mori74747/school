#include   <stdio.h>    //  ファイル操作・入出力関数用ヘッダファイル  
#include   <hamakou.h>  //  浜工情報技術科ヘッダファイル  

main()
{
  int  x;     //  シフト演算をおこなう変数  
  int  y, z;  //  演算結果を格納する変数    

  x = 500;    //  初期値設定                

  printf("x      : %s = %5d (0x%08X)\n", int2bit(x), x, x);
  y = x << 2;    //  左シフト演算  
  printf("x << 2 : %s = %5d (0x%08X)\n", int2bit(y), y, y);
  z = x >> 2;    //  右シフト演算  
  printf("x >> 2 : %s = %5d (0x%08X)\n", int2bit(z), z, z);

  return(0);
}
