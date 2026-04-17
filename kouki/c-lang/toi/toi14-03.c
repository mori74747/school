#include <stdio.h>

int threeTimes(void);

main()
{
  int i;

  for (i = 1; i <= 10; i++) {
    printf("%2d回目: %d\n", i, threeTimes());
  }

  return(0);
}

int threeTimes(void)
{

}
