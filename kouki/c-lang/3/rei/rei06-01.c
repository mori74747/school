#include <stdio.h>
#include <math.h>
#include <hamakou.h>

main()
{
  double x;  //  変数 xをdouble型で宣言 
  double y;  //  変数 yをdouble型で宣言 
  
  x = getfloat("x = ");  //  xにdouble型の値を入力  
  y = getfloat("y = ");  //  yにdouble型の値を入力  

  printf("%gの%g乗 = %g\n", x, y, pow(x,y));
  
  return(0);
}
