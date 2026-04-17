#include <stdio.h>

main()
{
  int i;  // クラスの番号 
  int s;  // 合計を格納   
  int zaiseki[8] = {39,38,34,40,37,39,35,39};  // ２年生のデータ 
  
  s = 0;  // 合計をクリア 
  for (i = 0; i < 8; i++) {
    s = s + zaiseki[i];
  }
  printf("２年生の生徒数は %d人です。\n", s);
  
  return(0);
}
