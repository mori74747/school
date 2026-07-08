#include <stdio.h>

typedef struct {
  int day;
  int hour;
  int minutes;
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
  Time time, time_sum = newTime(0, 0, 0);

  time = inputTime();
  while (!(getDay(time) == 0 && getHour(time) == 0 && getMinutes(time) == 0)){
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
  sscanf(buff, "%d, %d, %d", &day, &hour, &minutes);
  while (!isRightTime(day, hour, minutes)) {
    printf("Input again.\n");
    printf("day, hour, minutes: ");
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d, %d, %d", &day, &hour, &minutes);
  }

  return(newTime(day, hour, minutes));
}

// 引数に与えられた 日数, 時, 分 の値が正しいかどうかチェックする
// [引　数] day:日数, houe:時, minutes:分
// [戻り値] 与えられた 日数, 時, 分 が正しいとき：1, 正しくないとき：0
int isRightTime(int day, int hour, int minutes)
{
  if (0 <= day && 0 <= hour && hour <= 23 && 0 <= minutes && minutes <= 59) {
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
  day     = getDay(time1)     + getDay(time2);
  hour    = getHour(time1)    + getHour(time2);
  minutes = getMinutes(time1) + getMinutes(time2);

  if(60 <= minutes){
    minutes /= 60;
    hour += 1;
  }
  if(24 <= hour){
    hour /= 24;
    day += 1;
  }

  return(newTime(day, hour, minutes));
}

// 引数に与えられた 日数, 時, 分 の値からTime型の時間を生成する
// [引　数] day:日数, houe:時, minutes:分
// [戻り値] day, houe:, minutes で表されるTime型の時間
Time newTime(int day, int hour, int minutes)
{
  Time time;
  
  time.day     = day;
  time.hour    = hour;
  time.minutes = minutes;

  return(time);
}

// Timeがたから日数の値を取り出す
// [引　数] time:日数を取り出すTime型の値
// [戻り値] 取り出された日数
int getDay(Time time)
{
  return(time.day);
}

// Timeがたから時間の値を取り出す
// [引　数] time:時間を取り出すTime型の値
// [戻り値] timeから取り出された時間
int getHour(Time time)
{
  return(time.hour);
}

// Timeがたから分の値を取り出す
// [引　数] time:分を取り出すTime型の値
// [戻り値] timeから取り出された分
int getMinutes(Time time)
{
  return(time.minutes);
}
