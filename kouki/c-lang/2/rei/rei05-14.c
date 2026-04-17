#include <stdio.h>

main()
{
  int a, b;

  //  bが100以下の間、aを1から順に1ずつ増やしながらbに加え、毎回aとbの値を表示する
  b = 0;
  for(a = 1; b <= 100; a = a + 1) {
    printf("a:%3d, b:%3d\n", a, b);
    b = b + a;
  }

  return(0);
}
