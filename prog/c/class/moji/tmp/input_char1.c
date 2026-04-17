#include <stdio.h>

main()
{
  char c;

  // 入力メッセージを表示したければ printf() を使う
  // printf("Input getchar: ");
  // 1文字を標準関数 getchar() で入力
  c = getchar();
  printf("入力文字: %c, 文字コード(16進数): %X\n", c, c);

  return(0);
}
