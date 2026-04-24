#include <stdio.h>
#include <hamakou.h>

main()
{
  char ch = 'A', str[100] = "ABC";
  int i, d;

  printf("変数 ch の文字は %c, 文字コードは %d(10), %X(16)\n", ch, ch, ch);
  ch = ch + 1;
  printf("変数 ch の文字は %c, 文字コードは %d(10), %X(16)\n", ch, ch, ch);

  if ('a' > 'A') {
    printf("a は A より大きい\n");
  } else {
    printf("a は A より小さい\n");
  }

  d = 'a' - 'A';
  printf("'a' - 'A' は、数値だと %d(10), %X(16)、文字だと'%c'\n", d, d, d);

  printf("配列 str の文字列は %s\n", str);
  i = 0;
  while (str[i] != '\0') {
    str[i] = str[i] + d;
    i = i + 1;
  }
  printf("配列 str の文字列は %s\n", str);

  return(0);
}
