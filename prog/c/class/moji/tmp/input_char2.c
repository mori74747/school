#include <stdio.h>
#include <hamakou.h>

main()
{
  char c;

  // 1文字を浜工関数 getcharacter() で入力
  // 入力時にメッセージを表示できる
  c = getcharacter("Input getcharacter: ");
  printf("入力文字: %c, 文字コード(16進数): %X\n", c, c);

  return(0);
}
