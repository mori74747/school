#include <stdio.h>

main()
{
  int *p = NULL;   // ポインタ変数の宣言(NULLポインタで初期化) 
  int x = 1;       // pがこのxを指すようにする                 

  p = &x;          // ポインタ変数 p へ変数 x のアドレスを代入 
  printf("変数xのアドレス = %p\n", p);    // ポインタ p を表示 
  printf("x  = %d\n", x);                 // 変数 x を表示     
  printf("*p = %d\n", *p);                // ポインタ p を表示 

  return(0);
}
