#include <stdio.h>
#include "date.h"   // date.hはこのファイル(date.c)と同一ディレクトリに配置する

// キーボードから yyyy/mm/dd の形で入力した日付文字列をDate型にして返す 
// 日付文字列の形式が正しくないときの戻り値は不定
Date getDate(void)
{
  char buff[15];
  Date date;

  fgets(buff, sizeof(buff), stdin);
  sscanf(buff, "%d/%d/%d", &date.year, &date.month, &date.day);

  return(date);
}

// 引数dateに格納されている日付を、yyyy/mm/dd の形で表示する
// 表示後、改行はしない
void printDate(Date date)
{
  printf("%4d/%02d/%02d", date.year, date.month, date.day);
  return;
}

// 2つの引数date1とdate2のうち、新しい方の日付を返す
Date laterDate(Date date1, Date date2)
{
  if (date1.year > date2.year) {
    return(date1);
  } else if (date1.year < date2.year) {
    return(date2);
  }else if (date1.month > date2.month) {
    return(date1);
  }else if (date1.month < date2.month) {
    return(date2);
  } else if (date1.day > date2.day) {
    return(date1);
  } else {
    return(date2);
  }
}
