#include <stdio.h>

main()
{
  char moji;  // 文字を格納する変数定義   
  int i,j;    // カウンタ変数定義         
  
  printf("     0 1 2 3 4 5 6 7 8 9 A B C D E F\n");
  printf("   +--------------------------------\n");
  for (i = 2; i <= 7; i++) {
    printf("%X |",i * 16);
    for (j = 0; j <= 0xf; j++) {
      moji = i * 16 + j;     // 文字コードを生成         
      printf(" %c",moji);    // 変数 moji を整数型で表示 
    }
    printf("\n");            // 行末で改行               
  }
  
  return(0);
}
