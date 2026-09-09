//--- ２つの日付文字列を入力し、新しい方を表示する ---
#include <stdio.h>
#include "date.h" // date.hはこのファイル(rei21-01.c)と同一ディレクトリに配置する

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
