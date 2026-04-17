/*
"Fine"が出力される
*/
#include <stdio.h>

main()
{
  int n = 50;

  if (n > 50) {
    printf("Rainy\n");
  } else {
    printf("Fine\n");
  }

  return(0);
}
/*
結果、"Fine"が出力された

n に 50 が代入されているため、 50 > 50 という条件式になる。
もちろんこの条件は偽なので、else の処理が実行される。
よって、"Fine"が出力される
*/