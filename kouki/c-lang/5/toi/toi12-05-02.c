#include <stdio.h>
#include <hamakou.h>

int isLeapYear(int year);

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

// [引　数]: int型　year
// [戻り値]: int型　yearが閏年である(1)、閏年でない(0)
// [機　能]: yearが閏年かどうかを1(true)または0(false)で返す
int isLeapYear(int year){

  // 400 で割り切れる or 100で割り切れないが、4で割り切れる なら
  if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
    return(1);
  }else{
    return(0);
  }
}