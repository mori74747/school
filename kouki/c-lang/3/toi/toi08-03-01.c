#include <stdio.h>

main(){

  char i = '0', j = '9';
  while(i <= '9'){
    printf("%c：%c\n", i, j);
    i++;
    j--;
  }
  return (0);
}