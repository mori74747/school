#include <stdio.h>

main()
{
  int a;  //  変数 a を宣言する   

  for( a = 1; a <= 1000000000; a *= 2 ) {  //  aを倍々に変化させる  
    printf("%10d\n",a);                    //  aの値を表示する      
  }

  return(0);
}
