#include   <stdio.h>

typedef enum {
  Sun, Mon, Tue, Wed, Thu, Fri, Sat, WeekNums //  WeekNumsは１週間の日数になる  
} WeekDay;

int main(void)
{
  WeekDay today;    //  WeekDay型はintではなくenum  
  char  *day_name[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satday"
  };

  // 日曜日から１週間分の曜日の番号と名前を表示 
  for (today = Sun; today < WeekNums; today++) {
    printf("%d: %s\n", today, day_name[today]);
  }

  return(0);
}
