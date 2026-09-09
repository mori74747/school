#include  <stdio.h>
#include  <stdlib.h>

main()
{
  int  *array_p;  //  確保する領域へのポインタ  
  int  i;         //  カウンタ変数              

  array_p =  (int *)malloc(sizeof(int) * 5);  //  ５個分の領域確保  
  if (array_p == NULL) {
    printf("メモリを確保できませんでした。\n");
    return(1);
  }

  for (i = 0; i < 5; i++) {
    array_p[i] = i * i;    //  ５個のデータを格納  
  }

  printf("int size = %d\n",  sizeof(int));
  //  各データの格納アドレスと内容を表示  
  for (i = 0; i < 5; i++) {
    printf("%d:address = %p, value = %d\n", i, &array_p[i], array_p[i]);
  }
  free(array_p);

  return(0);
}
