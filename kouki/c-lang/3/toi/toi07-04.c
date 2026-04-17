#include <stdio.h>
#include <hamakou.h>

main()  // バブルソート 
{
  int n = getint("Input n: ");  // データ数の入力
  float t[n];  //  n個のデータを用意する 
  int i, j;    //  カウンタ変数としてｉ,ｊを用意  
  float temp;  //  入れ替えのための一時使用変数   
  
  for(i = 0; i < n; i++){
    printf("t[%d] = ",i);
    t[i] = getfloat("");
  }

  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (t[j] < t[j + 1]) {
        temp = t[j];        // -+                
        t[j] = t[j + 1];    //  |- 入れ替え処理  
        t[j + 1] = temp;    // -+                
      }
    }
  }

  printf("*** 身長の高い順 ***\n");
  for (i = 0; i < n; i++) {
    printf("%d人目の身長：%gcm\n", i + 1, t[i]);
  }
  
  return(0);
}
