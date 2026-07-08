#include <stdio.h>

main()
{
  char s[3][6] = {"ABC", "12345", "hamako"};
  char c;

  c = *(*(s + 2) + 4); 
  printf("%c\n", c);
}
