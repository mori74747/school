#include <stdio.h>

// Data型の定義
               {
               year;
               month;
               day;
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
}

// Data型の値を yyyy/mm/dd の形式で表示する
// [引　数] date: 表示する日付
// [戻り値] なし
void printDate(Date date)
{
}

// 引数で与えられた２つの日付の新しい方を返す
// [引　数] date1:１つ目の日付, date2:２つ目の日付
// [戻り値] date1 と date2 の新しい方の日付
Date laterDate(Date date1, Date date2)
{
}
