#include <stdio.h>

main()
{
  int dec;        //  数値入力用変数  
  char buf[256];  //  一時入力用変数  

  do {
    printf("整数を入力してください。\n");
    fgets(buf, sizeof(buf), stdin);  // キーボードより１行入力         
    sscanf(buf, "%d", &dec);         // bufの文字列を10進整数に変換    
    printf("dec = %d\n", dec);       // 入力した10進整数を10進数で表示 
  } while (dec != 0);                // 0を入力したら終了              

  return(0);
}
