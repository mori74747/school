#include <stdio.h>

void foo(int a[]);

main()
{
  int a[100];

  printf("int         : %3d Byte\n", sizeof(int));
  printf("a[] in main : %3d Byte\n", sizeof(a));

  foo(a);

  return(0);
}

void foo(int a[])
{
  printf("a[] in foo  : %3d Byte\n", sizeof(a));

  return;
}
