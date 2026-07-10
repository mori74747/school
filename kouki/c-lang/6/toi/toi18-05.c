#include <stdio.h>
#include <string.h>

main()
{
  char name[256], *mei, *sei;

  printf("「名/姓」からなる文字列を入力してください\n");
  printf("［例 Tarou/Hamakou ］: ");
  mei = fgets(name, sizeof(name), stdin);

  sei = strchr(name, '/');

  if (sei == NULL) {
    printf("入力した文字列に\"/\"が含まれていません。\n");
  } else {
    *sei = '\0';
    sei = sei+1;
    printf("名: %s, 姓: %s\n", mei, sei);
  }

  return(0);
}
