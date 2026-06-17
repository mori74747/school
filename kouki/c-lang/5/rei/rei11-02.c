#include <stdio.h>
main()
{
int i,n;
n = 0;
for (i = 1; i <= 10; i++) {
n += i;
}
printf("10までの自然数の和は %d\n",n);
return(0);
}
