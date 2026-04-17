#include <stdio.h>

main()
{
  int a = 25;   // 変数aの宣言と同時に初期値25を代入
  int b = 4;    // 変数bの宣言と同時に初期値 4を代入

  printf("-a + b = %d\n", -a + b);     // 加算
  printf("-a - b = %d\n", -a - b);     // 減算
  printf("a * (-b) = %d\n", a * (-b)); // 乗算
  printf("a / b = %d\n", a / b);       // 除算
  printf("a \% b = %d\n", a % b);      // 余り

  return(0);
}
