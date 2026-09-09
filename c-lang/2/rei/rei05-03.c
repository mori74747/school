#include <stdio.h>

main()
{
  int a = 10;
  int b = 0;

  if (a <= b) {         // 関係演算子の書き間違い     
    printf("変数 a は 変数 b 以下である\n");
  }
  if (a = b) {          // Ｃ言語文法上のミスではない 
    printf("変数 a は 変数 b と等しい\n");
  }
  return(0);
}
