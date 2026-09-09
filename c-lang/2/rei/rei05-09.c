#include <stdio.h>
#include <hamakou.h>

main()
{
  int rank;

  rank = getint("順位を入力してください。");    //  順位を入力する  

  switch(rank) {
    case 1:
      printf("優勝したあなたには、海外旅行です。\n");
      break;
    case 2:
      printf("２位のあなたには、国内旅行です。\n");
      break;
    case 3:
      printf("３位のあなたには、ホテルの食事券です。\n");
      break;
    default:
      printf("タオルをどうぞ。\n");
      break;
  }
  return(0);
}
