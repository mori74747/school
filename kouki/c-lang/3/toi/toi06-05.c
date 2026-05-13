#include <stdio.h>
#include <math.h>

main()
{
  int i,j;
  
  // for (i = 1; i >= 10); {
  // 比較演算子の向きが逆、更新式がない、セミコロンは初期化と比較式にしかつけない。
  for(i = 1; i <= 10; i++){
    // for (j = 1; j > 5); {
    // 比較演算子の向きが逆、更新式がない、セミコロンは初期化と比較式にしかつけない。
    for(j = 1; j < 5; j++){
      printf("%dの %d乗は %dです\n", i, j, pow(i,j);
    }
  }

  return(0);
}
