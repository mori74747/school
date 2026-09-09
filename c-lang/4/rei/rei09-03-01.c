#include <stdio.h>
      
main()
{
  int i, j;       // iはクラスの番号, jは学年の番号
  int s[4] = {};  // 学年別の合計を格納(0で初期化)
  int c[7] = {};  // クラス別の合計を格納(0で初期化)
  int zaiseki[4][7] = {
    {41,40,40,40,40,41,41},   // １年生のデータ  
    {39,38,34,40,37,39,35},   // ２年生のデータ  
    {30,39,31,40,38,40,33},   // ３年生のデータ 
    {30,39,31,40,38,40,33}    // ４年生のデータ  
  };
  int class, grade;
  
  grade = sizeof(zaiseki)    / sizeof(zaiseki[0]);
  class = sizeof(zaiseki[0]) / sizeof(zaiseki[0][0]);

  for (j = 0; j < grade; j++) {          // jは学年の番号   
    for (i = 0; i < class; i++) {        // iはクラスの番号 
      s[j] = s[j] + zaiseki[j][i];   // j+1学年の合計   
      c[i] = c[i] + zaiseki[j][i];   // i+1組の合計     
    }
  }
  for (i = 0; i < grade; i++) {
    printf("%d年生の生徒数は %d人です。\n", i + 1, s[i]);
  }
  for (i = 0; i < class; i++) {
    printf("%d組の生徒数は %d人です。\n", i + 1, c[i]);
  }
  
  return(0);
}
