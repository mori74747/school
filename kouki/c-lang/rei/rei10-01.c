#include <stdio.h>
#include <hamakou.h>
      
main()
{
  int c; //  入力文字格納用変数  

  while ((c = getchar()) != EOF) {   //  EOFを入するまで繰り返す  
    putchar(c);                      //  標準出力に１文字出力   
  }

  return(0);
}
