#include <stdio.h>
#include <hamakou.h>

main()
{
  char s[100];
  int n, i;

  // 文字列を浜工関数 getstring() で入力
  n = getstring("Input getstring: ", s);
  printf("入力文字列 = %s, 文字列の長さ = %d\n", s, n);

  i = 0;
  while (s[i] != '\0') {                      // ヌル文字に到達するまで
    printf("s[%d]: %c, %X\n", i, s[i], s[i]); // s[] を1文字ずつ表示
    i = i + 1;
  }

  return(0);
}
