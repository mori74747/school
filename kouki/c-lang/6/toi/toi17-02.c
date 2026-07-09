#include <stdio.h>
/*
[予想]
iのアドレス 10 3 2 

*/
main()
{
  unsigned int i = 3, *p = &i;
  printf("%u %u %u %u\n", p, *p+7, **&p, p-(p-2));

  return(0);
}