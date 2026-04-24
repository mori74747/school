#include<stdio.h>

               {
  int numerator;   // 分子
  int denominator; // 分母
} Fraction;

main()
{
  char buff[256];
           a, b, c;

  // 分数aをキーボードより入力する
  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d/%d",             ,               );

  // 入力した分数aを表示
  printf("a = %d/%d\n",            ,              );

  // 分数bは2/3
  b.numerator =  ;
  b.denominator =  ;

  // 分数bを表示
  printf("b = %d/%d\n",            ,              );

  // c = a * b
  c.numerator =                          ;
  c.denominator =                              ;

  // 乗算結果である分数cの表示
  printf("a * b = %d/%d\n",            ,              );

  return(0);
}
