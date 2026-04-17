#include <stdio.h>

main()
{
  printf("char        = %d\n", sizeof(char));
  printf("short       = %d\n", sizeof(short));       //  int型よりは長くない
  printf("int         = %d\n", sizeof(int));
  printf("long        = %d\n", sizeof(long));        //  int型よりは短くない
  printf("long long   = %d\n", sizeof(long long));   //  long型よりは短くない
  printf("float       = %d\n", sizeof(float));
  printf("double      = %d\n", sizeof(double));
  printf("long double = %d\n", sizeof(long double)); //  double型よりは短くない

  return(0);
}
