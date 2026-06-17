/*
予想
  z = 7 と表示。
*/

#include <stdio.h>
      
int  z;
void f( int x );
      
main()
{
  z = 5;
  f(z);
  printf("z = %d\n", z);

  return(0);
}

void f( int x )
{
  x = 2;
  z += x;

  return;
}

/*
理由
  仮引数x に 実引数z が代入され、 x = 5 となる。
  その後、x に 2 が代入され、 x = 2 と変化する。
  その後、グローバル変数であるzを参照し、zにxを加算するため、 z = 7 となる。
  そのため、 z = 7 と表示される。
*/