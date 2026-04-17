#include <stdio.h>
#include <math.h>

main()
{
  double x = 3.0;  //  変数 xを宣言し、3.0を設定  
  double y = 4.0;  //  変数 yを宣言し、4.0を設定  
  double z;
  
  z = sqrt(x * x + y * y);
  printf("SQRT(%g^2 + %g^2) = %g\n", x, y, z);
  
  return(0);
}
