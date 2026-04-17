#include <stdio.h>
#include <hamakou.h>



main()
{
  int year;

  year = getint("西暦年: ");
  putchar('\n');
  switch (isLeapYear(year)) {
    case 0:
      printf("平年\n");
      break;
    case 1:
      printf("閏年\n");
      break;
  }
  return(0);
}
