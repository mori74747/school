#include <stdio.h>

main()
{
  char  *week[7] = {"Sunday", "Monday", "Tuesday",
                    "Wednesday", "Thursday", "Friday", "Saturday"};

  char  **p;
  int  i;

  p = week;
  for (i = 0; i < 7; i++) {
    for(int j = 0; j < 3; j++){
        printf("%c", *(*(p + i) + j));
    }
    putchar('\n');
  }
  return(0);
}
