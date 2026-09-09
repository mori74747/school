#include <stdio.h>

main()
{
  int s, total;  //  変数 s,totalを宣言する  

  s = 1;         //  sに 1を設定する         
  total = 0;     //  totalをクリアする       

  do {
    total = total + s;  //  totalに合計を求める   
    s = s + 1;          //  sを +1する            
  } while(s <= 10);     //  sが 10だったら繰返し  

  printf("1から 10までの和は %d です。\n",total);

  return(0);
}
