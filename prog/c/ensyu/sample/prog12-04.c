#include <stdio.h>
#include <hamakou.h>





int main(void)
{
  int m, n;
  char c;

  n = getint("列数: ");
  m = getint("行数: ");
  
  c = getcharacter("長方形を描く文字: ");
  printf("\n");
  chRectangle(c, m, n);

  c = getcharacter("三角形を描く文字: ");
  printf("\n");
  chTriangle(c, m);
  
  return(0);
}
