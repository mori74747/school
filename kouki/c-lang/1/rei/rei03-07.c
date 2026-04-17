#include <stdio.h>

main()
{
  int i;
  float f;

  i = 65;
  f = 12.34;

  printf("10進数　　　　　　　：%d\n", i);     // 10進表示
  printf(" 8進数　　　　　　　：%o\n", i);     //  8進表示
  printf("16進数　　　　　　　：%x\n", i);     // 16進表示
  printf("10進数（桁指定あり）：%4d\n", i);    // 10進表示（桁指定あり）
  printf(" 8進数（桁指定あり）：%4o\n", i);    //  8進表示（桁指定あり）
  printf("16進数（桁指定あり）：%4x\n", i);    // 16進表示（桁指定あり）
  printf("\n");
  printf("float型（桁指定なし）：%f\n", f);    // float型表示 */
  printf("float型（桁指定あり）：%7.1f\n", f); // float型（桁指定あり）

  return(0);
}
