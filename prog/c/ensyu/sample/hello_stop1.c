#include <stdio.h>

int main(void)
{
  static int cnt = 5;

  if (cnt > 0) {
    printf("Hello world.\n");
    cnt--;
    main();
  }
  return(0);
}
