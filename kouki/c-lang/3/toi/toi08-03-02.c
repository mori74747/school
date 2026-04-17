#include <stdio.h>

main(){

  int i = 0;
  char s[10] = "";
  while(i <= 9){
    printf("%c：%s\n", '0'+ i, s);
    i++;
    s[i-1] = ('0'+ i );
  }
  return (0);
}