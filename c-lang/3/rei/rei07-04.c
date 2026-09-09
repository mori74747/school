#include <stdio.h>

main()  // バブルソート 
{
  float t[5] = {148.5, 163.2, 183.5, 156.7, 172.5}; //  ５つのデータを用意する  
  int i, j;    //  カウンタ変数としてｉ,ｊを用意  
  float temp;  //  入れ替えのための一時使用変数   
  
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4 - i; j++) {
      if (t[j] < t[j + 1]) {
        temp = t[j];        // -+                
        t[j] = t[j + 1];    //  |- 入れ替え処理  
        t[j + 1] = temp;    // -+                
      }
    }
  }

  printf("*** 身長の高い順 ***\n");
  for (i = 0; i < 5; i++) {
    printf("%d人目の身長：%gcm\n", i + 1, t[i]);
  }
  
  return(0);
}
