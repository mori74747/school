#include <stdio.h>
main()
{
  float t[5];  //  ５つの変数を用意する        
  int i;       //  カウンタ変数としてｉを用意  
  
  t[0] = 148.5;
  t[1] = 163.2;
  t[2] = 183.5;
  t[3] = 156.7;
  t[4] = 172.5;
  
  //  for文を使ってデータを出力   
  for (i = 0; i < 5; i++) {
    printf("%d人目の身長：%gcm\n", i + 1, t[i]);
  }
  return(0);
}
