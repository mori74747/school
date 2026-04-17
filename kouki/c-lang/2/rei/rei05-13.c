#include <stdio.h>

main()
{
  int a, b;

  //  bが100以下の間、aを1から順に1ずつ増やしながらbに加え、毎回aとbの値を表示する
  for( a = 1, b = 0; b <= 100; b = b + a, a = a + 1) { 
    printf("a:%3d, b:%3d\n", a, b);
  }

  return(0);
}
