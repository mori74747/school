#include <stdio.h>
      
main()
{
  char a;          //  文字入力用変数    
  char b[10];      //  文字列入力用変数  

  printf("文字を入力してください。=> ");
  scanf("%c",&a); //  １文字を入力（１データを１変数に格納）  
      
  printf("文字列を入力してください。=> ");
  scanf("%s",b);  //  文字列を文字配列に格納  

  printf("入力文字   ＝ %c\n" ,a);
  printf("入力文字列 ＝ %s\n" ,b);

  return(0);
}
