#include <stdio.h>

float triangle( float width, float height );  //  三角形の面積を求める関数  

main()
{
  printf("三角形１：%6.2fcm2\n", triangle(1.3, 8.3));
  printf("三角形２：%6.2fcm2\n", triangle(4.8, 9.8));
  printf("三角形３：%6.2fcm2\n", triangle(1.2, 2.0));

  return(0);
}

float triangle( float width, float height )
{
  float area; //  三角形の面積  

  area = width * height / 2.0;  //（底辺 × 高さ）÷ ２  

  return(area);
}
