#include <stdio.h>

// Data型の定義
typedef struct{
  unsigned int year;
  unsigned int month;
  unsigned int day;
} Date;

Date getDate(void);
void printDate(Date date);
Date laterDate(Date Date1, Date Date2);

main()
{
  Date Date1, Date2, Date3;

  printf("日付１(yyyy/mm/dd): ");
  Date1 = getDate();
  printf("日付２(yyyy/mm/dd): ");
  Date2 = getDate();
  Date3 = laterDate(Date1, Date2); 
  printDate(Date3);

  putchar('\n');

  return(0);
}

// キーボードから 年,月,日 を yyyy/mm/dd の形式で入力し、Date型の値として返す
// [引　数] なし
// [戻り値] yyyy/mm/dd 形式で入力された Date型の値
Date getDate(void)
{
  char buff[256];
  fgets(buff, sizeof(buff), stdin);

  Date date;
  sscanf(buff, "%u/%u/%u", &date.year, &date.month, &date.day);

  return(date);
}

// Data型の値を yyyy/mm/dd の形式で表示する
// [引　数] date: 表示する日付
// [戻り値] なし
void printDate(Date date)
{
  printf("%04u/%02u/%02u\n", date.year, date.month, date.day);
  return;
}

// 引数で与えられた２つの日付の新しい方を返す
// [引　数] date1:１つ目の日付, date2:２つ目の日付
// [戻り値] date1 と date2 の新しい方の日付
Date laterDate(Date date1, Date date2)
{
  unsigned int date1_year  = date1.year;
  unsigned int date2_year  = date2.year;
  unsigned int date1_month = date1.month;
  unsigned int date2_month = date2.month;
  unsigned int date1_day   = date1.day;
  unsigned int date2_day   = date2.day;

  if(date1_year < date2_year){
    return(date1);
  }
  else if(date1_year > date2_year){
    return(date2);
  }
  else{
    if(date1_month < date2_month){
      return(date1);
    }
    else if(date1_month > date2_month){
      return(date2);
    }
    else{
      if(date1_day < date2_day){
        return(date1);
      }
      else{
        return(date2);
      }
    }
  }

}
