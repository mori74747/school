#include <stdio.h>
#include <hamakou.h>

main()
{
  int rank;
  rank = getint("順位を入力してください。");    //  順位を入力する  
      
  if (rank == 1) {
    printf("優勝したあなたには、海外旅行です。\n");
  } else if (rank == 2) {
    printf("２位のあなたには、国内旅行です。\n");
  } else if (rank == 3) {
    printf("３位のあなたには、ホテルの食事券です。\n");
  } else {
    printf("タオルをどうぞ。\n");
  }
  return(0);
}
