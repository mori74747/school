#include <stdio.h>

void yoko( void );  //  横線を表示する関数  
void tate( void );  //  縦線を表示する関数  

main()
{
  int i;   //  カウンタ変数の宣言  

  yoko();  //  横線の表示  

  for (i = 1; i <= 4; ++i) { //  ４回繰返し  
    tate();                  //  縦線の表示  
  }

  yoko();  //  横線の表示  

  return(0);
}

void yoko( void )
{
  printf("+--------+\n");
  return;
}

void tate( void )
{
  printf("|        |\n");
  return;
}
