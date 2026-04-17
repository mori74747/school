#include <stdio.h>

void ast7( void );

main()
{
  int i;  //  カウンタ変数の宣言  

  for (i = 1; i <= 5; i++) {  //  繰返し処理  
    ast7();                   //  関数ast7()の呼出し  
  }

  return(0);
}

void ast7( void )
{
  int i;  //  ループ変数の宣言  

  for ( i = 1; i <= 7; i++) { //  繰返し処理  
    putchar('*');             //  「*」の表示  
  }

  putchar('\n');   //  改行  

  return;
}
