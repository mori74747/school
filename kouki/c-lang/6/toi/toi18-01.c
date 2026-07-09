//  配列中の０が見つかるまでの個数をカウント  

#include <stdio.h>

main()
{
  int  array[10] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
  int  *array_p;

  array_p = array;
  while(*array_p != 0) {
    array_p++;
  }
  printf("0が見つかるまでのデータ数は %d個です。\n", array_p - array + 1);

  return(0);
}
