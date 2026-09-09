#include <stdio.h>

main()
{
  int dec = 0;  //  数値入力用変数  

  do {
    printf("整数を入力してください。\n");
    scanf("%d", &dec);          // 文字列を10進整数として入力 
    printf("dec = %d\n", dec);  // 入力した10進整数を表示     
  } while (dec != 0);           // 0を入力したら終了          

  return(0);
}
