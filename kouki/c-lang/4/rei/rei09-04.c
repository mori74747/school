#include <stdio.h>

main()
{
  int week;    // 曜日を 0〜6 で表す 
  int i = 0;   // カウンタ変数宣言   
  char weekname[7][10] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
    };
  
  // 各曜日を１文字ずつ表示 
  printf("***** １文字ずつ表示 *****\n");
  for (week = 0; week < 7; week++) {
    i = 0;
    while(weekname[week][i] != '\0') {
      printf("%c",weekname[week][i]);
      i++;
    }
    printf("\n");
  }

  // 各曜日を文字列として表示 
  printf("***** 文字列として表示 *****\n");
  for (week = 0; week < 7; week++) {
    printf("%s\n",weekname[week]);
  }

  return(0);
}
