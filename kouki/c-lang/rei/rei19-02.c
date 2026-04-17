#include <stdio.h>

void  ch_line(char ch, int n);

int main(int argc, char *argv[])
{
  int  i;     //  カウンタ変数  
  int  size;  //  三角形の大きさ  
  int  spc;   //  ' 'の数  
  int  len;   //  '+'の数  

  if ( argc <= 1 ) { //  パラメータが未指定の場合  
    printf("表示する三角形の大きさをパラメータとして付加して下さい。\n");
  } else {
    sscanf(argv[1], "%d", &size); // １つ目のパラメータを文字（数字）から数値に変換  

    len = 1;
    spc = size;
    for ( i = 1; i <= size; i++) {
      spc--;
      ch_line(' ', spc);
      ch_line('+', len);
      putchar('\n');
      len += 2;
    }
  }
  return(0);
}

void  ch_line(char ch, int n)
{
  int i;

  for (i = 0; i < n; i++) {
    putchar(ch);
  }
  return;
}
