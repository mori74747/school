#include <stdio.h>

main()
{
  int Lab;      // int  1ab;
  int  abc;
  int  _de;
  int  fg;      // int fg!;
  int If;       // int  if;

  Lab = 100;    // 1ab = 100;
  abc = 200;
  _de = 300;
  fg = 400;     // fg! = 400;
  If = 500;     // if  = 500;

  printf("Lab = %d\n", Lab);    // printf("123 = %d\n", 1ab);
  printf("abc = %d\n", abc);
  printf("_de = %d\n", _de);
  printf("fg = %d\n", fg);     // printf("fg! = %d\n", fg!);
  printf("If = %d\n", If);      // printf("if = %d\n", if);

  return(0);
}

/*
変数名にC言語の予約語は使えないので、"if"や"lab"などは、エラーが出る。
さらに、変数名に"!"などの記号は使えないので、エラーが出る。
*/