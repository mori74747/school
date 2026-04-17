#include <stdio.h>

main()
{
  int   year, month, day;
  float x, y;

  printf("今日の年月日をスペースで区切って入力してください：");
  scanf("%d %d %d", &year, &month, &day);  // 整数をスペースで区切って入力 
  printf("%d年%d月%d日\n", year, month, day);

  printf("今日の年月日を yyyy-mm-dd のように入力してください：");
  scanf("%d-%d-%d", &year, &month, &day);  // 整数を"-"で区切って入力 
  printf("%d年%d月%d日\n", year, month, day);

  printf("実数x, yをスペースで区切って入力してください：");
  scanf("%g %g", &x, &y);                  // 実数をスペースで区切って入力 
  printf("%g + %g = %g\n", x, y, x + y);

  printf("実数x, yを x, y のように入力してください：");
  scanf("%g,%g", &x, &y);                  // 実数を","で区切って入力 
  printf("%g + %g = %g\n", x, y, x + y);

  return(0);
}
