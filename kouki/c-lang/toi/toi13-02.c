#include <stdio.h>
      
int s = 0;

main()
{
  int a = 1, b = 2, c = 3;

  s = a + b + c;
  printf("%d %d %d %d\n", a, b, c, s);
  {
    int   b = 4;
    float c = 5.0;

    printf("%d %d %g\n", a, b, c);
    a = b;
    {
      int c;

      c = b;
      s = a + b + c;
      printf("%d %d %d\n", a, b, c);
    }
    printf("%d %d %g\n", a, b, c);
  }
  printf("%d %d %d %d\n", a, b, c, s);
}
