#include <stdio.h>
#include <math.h>

main()
{
  int t;             // 角度設定用変数定義             
  int s;             // 計算結果格納変数定義           
  double pi = M_PI;  // πの値(3.14159265358979323846) 
  int i;             // カウンタ用変数                 
  
  for (t = 0; t <= 360; t += 15) {
    printf("%3d ",t);                    // 角度の表示                               
    s = sin((double)t * pi / 180) * 20;  // 表示のためにsin(t)の計算結果を20倍に拡大 
    for (i = 1; i <= s + 20; i++) {
      printf(" ");                       // sin(t)*20個分の「 」(スペース)を表示     
    }
    printf("*\n");
  }
  
  return(0);
}
