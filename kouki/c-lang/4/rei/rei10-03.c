#include <stdio.h>
#include <hamakou.h>
      
main()
{
  int c[4];

  keybuff("off");  // バッファリングを無効にする 
  c[0] = getchar(); printf("%02X\n", c[0]);
  c[1] = getchar(); printf("%02X\n", c[1]);
  c[2] = getchar(); printf("%02X\n", c[2]);
  c[3] = getchar(); printf("%02X\n", c[3]);
  keybuff("on");   // バッファリングを有効にする 

  return(0);
}
