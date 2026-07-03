#include <stdio.h>

typedef struct {
         ;
          ;
             ;
} Time;

Time newTime(int day, int houre, int miniutes);
int getDay(Time time);
int getHour(Time time);
int getMinutes(Time time);

Time inputTime(void);
int isRightTime(int day, int hour, int miniutes);
Time timeAdd(Time time1, Time time2);

main()
{
  Time time, time_sum = newTime(        );

  time = inputTime();
  while (                                                                );
    time_sum = timeAdd(time_sum, time);
    printf("sum = %d %d %d\n", getDay(time_sum), getHour(time_sum), getMinutes(time_sum));
    time = inputTime();
  }

  return(0);
}

// 日数, 時, 分 の値をこの順序でカンマ区切りで入力し、Time型の値として返す
// [引　数] なし
// [戻り値] 日数, 時, 分を格納したTime型の値
Time inputTime(void)
{
  char buff[256];
  int day, hour, minutes;

  printf("day, hour, minutes: ");
  fgets(buff, sizeof(buff), stdin);
                                                 ;
  while (                                ) {
    printf("Input again.\n");
    printf("day, hour, minutes: ");
    fgets(buff, sizeof(buff), stdin);
                                                   ;
  }

  return(newTime(day, hour, minutes));
}

// 引数に与えられた 日数, 時, 分 の値が正しいかどうかチェックする
// [引　数] day:日数, houe:時, minutes:分
// [戻り値] 与えられた 日数, 時, 分 が正しいとき：1, 正しくないとき：0
int isRightTime(int day, int hour, int minutes)
{
  if (                                                                   ) {
    return(1);
  } else {
    return(0);
  }
}

// ２つの時間の和を新しい時間として返す
// [引　数] time1:１つ目の時間, time2:２つ目の時間 
// [戻り値］time1とtime2の合計時間
Time timeAdd(Time time1, Time time2)
{
  int day, hour, minutes;

  return(newTime(day, hour, minutes));
}

// 引数に与えられた 日数, 時, 分 の値からTime型の時間を生成する
// [引　数] day:日数, houe:時, minutes:分
// [戻り値] day, houe:, minutes で表されるTime型の時間
Time newTime(int day, int hour, int minutes)
{
  Time time;
  
           = day;
            = hour;
               = minutes;

  return(    );
}

// Timeがたから日数の値を取り出す
// [引　数] time:日数を取り出すTime型の値
// [戻り値] 取り出された日数
int getDay(Time time)
{
}

// Timeがたから時間の値を取り出す
// [引　数] time:時間を取り出すTime型の値
// [戻り値] timeから取り出された時間
int getHour(Time time)
{
}

// Timeがたから分の値を取り出す
// [引　数] time:分を取り出すTime型の値
// [戻り値] timeから取り出された分
int getMinutes(Time time)
{
}
