#include <stdio.h>
#include <stdlib.h>

enum Week {
  Sun, Mon, Tue, Wed, Thu, Fri, Sat
};

main(int argc, char *argv[])
{
  int year, month, day;     // 入力される年月日
  int i, m;                 // カウンタ変数
  int days = 1;             // 現在までの日数+基準の曜日（日本で使われる西暦では0001/01/01は月曜日のため初期値は1とする）
  int leap;                 // うるう年かどうか判定する
  enum Week week;           // 入力された年月日の曜日

  // 入力のチェック　
  if(argc != 2 || sscanf(argv[1], "%d/%d/%d", &year, &month, &day) != 3){
    fprintf(stderr, "不正な入力です\n\n");
    exit(2);
  }
  // 入力のチェック(年)(月)
  if(year < 1 || month < 1 || month > 12 || day < 1){
    fprintf(stderr, "不正な入力です\n");
    exit(2);
  }

  // うるう年の判定
  leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

  // 入力のチェック(日)
  if(month == 2){
    if(day > (leap ? 29 : 28)){
      fprintf(stderr, "不正な入力です\n");
      exit(2);
    }
  }else if(month == 4 || month == 6 || month == 9 || month == 11){
    if(day > 30){
      fprintf(stderr, "不正な入力です\n");
      exit(2);
    }
  }else if(day > 31){
    fprintf(stderr, "不正な入力です\n");
    exit(2);
  }

  // 前月までの日数を加算
  for(m = 1; m < month; m++){
    if(m == 2){
      if(leap){
        days += 29;
      }else{
        days += 28;
      }
    }else if (m == 4 || m == 6 || m == 9 || m == 11){
      days += 30;
    }else{
      days += 31;
    }
  }
  days += day - 1;

  // 前年までの日数を加算
  for (i = 1; i < year; i++){
    if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
      days += 366;
    }else{
      days += 365;
    }
  }

  // 曜日の計算
  week = (enum Week)(days % 7);

  printf("%04d/%02d/%02d の曜日は", year, month, day);

  switch(week){
    case Sun: printf("日曜日"); break;
    case Mon: printf("月曜日"); break;
    case Tue: printf("火曜日"); break;
    case Wed: printf("水曜日"); break;
    case Thu: printf("木曜日"); break;
    case Fri: printf("金曜日"); break;
    case Sat: printf("土曜日"); break;
  }
  printf("です。\n");

  return (0);
}
