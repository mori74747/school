#include <stdio.h>
      
main()
{
  int i;           // クラスの番号 
  int s[3] = {};   // 学年別の合計を格納(0で初期化) 
  int zaiseki1[8] = {41,40,40,40,40,41,41,42};  // １年生のデータ 
  int zaiseki2[8] = {39,38,34,40,37,39,35,39};  // ２年生のデータ 
  int zaiseki3[8] = {30,39,31,40,38,40,33,36};  // ３年生のデータ
  int classsum[8] = {};                         // クラス毎の合計 
  
  for (i = 0; i < 8; i++) {
    s[0] = s[0] + zaiseki1[i];  // １年生の集計 
    s[1] = s[1] + zaiseki2[i];  // ２年生の集計 
    s[2] = s[2] + zaiseki3[i];  // ３年生の集計 

    classsum[i] = zaiseki1[i] + zaiseki2[i] + zaiseki3[i]; // クラス別合計
  }

  for (i = 0; i < 3; i++) {
    printf("%d年生の生徒数は %d人です。\n", i + 1, s[i]);
  }
  for (i = 0; i < 8; i++){
    printf("%dクラスの合計は %d人です。\n", i + 1, classsum[i]);
  }
  
  return(0);
}
