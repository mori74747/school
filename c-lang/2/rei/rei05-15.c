#include <stdio.h>
main()
{
  int i,n;  //  変数 i,nを宣言する        

  /**********    for 文    **********/
  for ( n = 0, i = 1; i <= 10; i = i + 1) {   //  1から 10まで iを変化する  
    n = n + i;                                //  nに合計を求める           
  }
  printf("for文で求めた和は %d\n",n);

  /**********   whlie 文   **********/
  n = 0;            //  nをクリアする             
  i = 1;            //  iに 1を設定               
  while(i <= 10) {  //  sが 10以下なら処理を実行  
    n = n + i;      //  nに合計を求める           
    i = i + 1;      //  iを +1する                
  }
  printf("while文で求めた和は %d\n",n);

  return(0);
}
