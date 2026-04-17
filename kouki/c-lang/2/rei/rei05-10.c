#include <stdio.h>
#include <hamakou.h>

main()
{
  int x;

  x = getint("1〜3の値を入力してください。");    //  値を入力する  

  printf("\n*****  すべての case に break文がある  *****\n");
  switch(x) {
    case 1:
      printf("1");
      break;
    case 2:
      printf("2");
      break;
    case 3:
      printf("3");
    break;
  }

  printf("\n*****  すべての case に break文がない  *****\n");
  switch(x) {
    case 1:
      printf("1");
    case 2:
      printf("2");
    case 3:
      printf("3");
  }

  printf("\n*****  case 2 にのみ break文がある  *****\n");
  switch(x) {
    case 1:
      printf("1");
    case 2:
      printf("2");
      break;
    case 3:
      printf("3");
  }

  printf("\n");

  return(0);
}
