#include <stdio.h>

main()
{
  int     i;  //  カウンタ変数  
  char    chr_d[3], *chr_p; //    char型変数・ポインタの宣言  
  int     int_d[3], *int_p; //     int型変数・ポインタの宣言  
  double  dbl_d[3], *dbl_p; //  double型変数・ポインタの宣言  

  chr_d[0] = 'a';
  chr_d[1] = 'b';
  chr_d[2] = 'c';

  int_d[0] = 100;
  int_d[1] = 200;
  int_d[2] = 300;

  dbl_d[0] = 1.111;
  dbl_d[1] = 2.222;
  dbl_d[2] = 3.333;

  chr_p = &chr_d[0];  //  先頭要素のアドレスを格納  
  for (i = 0; i < 3; i++) {
    printf("chr_d[%d]: chr_p = %p, *chr_p = %c\n", i, chr_p, *chr_p);
    chr_p++;          //  ポインタをインクリメント  
  }

  int_p = &int_d[0];  //  先頭要素のアドレスを格納  
  for (i = 0; i < 3; i++) {
    printf("int_d[%d]: int_p = %p, *int_p = %d\n", i, int_p, *int_p);
    int_p++;          //  ポインタをインクリメント  
  }

  dbl_p = &dbl_d[0];  //  先頭要素のアドレスを格納  
  for (i = 0; i < 3; i++) {
    printf("dbl_d[%d]: dbl_p = %p, *dbl_p = %g\n", i, dbl_p, *dbl_p);
    dbl_p++;          //  ポインタをインクリメント  
  }

  return(0);
}
