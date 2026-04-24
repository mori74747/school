#include <stdio.h>
#include <hamakou.h>

main()
{
  char ch = 'A', str[10] = "ABC";
  int i;

  printf("変数 ch の文字は %c\n", ch);
  printf("%c の文字コードは\n", ch);
  printf("10進数で %d\n", ch);
  printf("16進数で %X\n\n", ch);

  printf("配列 str の文字列は %s\n\n", str);

  i = 0;
  for (i = 0; str[i] != '\0'; i++) {
    printf("str[%d] の文字は %c\n", i, str[i]);
  }
  putchar('\n');

  for (i = 0; i < 10; i++) {
    printf("str[%d] の文字は %c\n", i, str[i]);
  }

  return(0);
}
