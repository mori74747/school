#include <stdio.h>

main()
{
  int j;
  long long i;   // int ⇒ long long 

  // froat x,y;
  double y;  // float y ⇒ double y

  int x;   // float x ⇒ int x

  // i = 12345678900;
  // int型には -2^31~(2^31)-1までの整数しか入らないので、上限を超えている
  
  // i = 12345678900;
  i = 12345678900ll;

  // j = 0xabcd
  // セミコロンがない
  j = 0xabcd;

  // x = 01234, 
  // 01234は0から始まる8進数表現なので、float型に入れない
  // カンマ","ではなくセミコロン";"
  x = 01234;

  // 1.23e47はfloatの範囲を超えている
  y = 123e45;

  // prontf("i + j = %f\n", i + j); i 
  // セミコロン付け忘れ・printfが違う、int型に%fは使えない
  // %f ⇒ %ld
  printf("i + j = %ld\n", i + j);

  // printf("x = %d  y = %f\n", x , y);
  printf("x = %d  y = %g\n", x , y);

  // retarn(0); スペルミス
  return (0);

// { の向きが違う
}