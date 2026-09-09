#include   <stdio.h>

typedef    int   WeekDay;

#define    Sun        0    //  日曜日        
#define    Mon        1    //  月曜日        
#define    Tue        2    //  火曜日        
#define    Wed        3    //  水曜日        
#define    Thu        4    //  木曜日        
#define    Fri        5    //  金曜日        
#define    Sat        6    //  土曜日        
#define    WeekNums   7    //  １週間の日数  

main()
{
  WeekDay  today;          // WeekDay型の実体はint
  char  *day_name[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Satday"
  };

  // 日曜日から１週間分の曜日の番号と名前を表示 
  for (today = Sun; today < WeekNums; today++) {
    printf("%d: %s\n", today, day_name[today]);
  }

  return(0);
}
