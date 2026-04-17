#include <stdio.h>

main()
{

  //書式制御文字が正しくない
  printf("%f\n", 1.23);  // printf("%d\n", 1.23);
  printf("%d\n", 512);   // printf("%f\n", 512);
  printf("%c\n", 'A');   // printf("%d\n", 'A');

  return(0);
}
