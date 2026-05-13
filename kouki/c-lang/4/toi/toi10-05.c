// [CTRL+D]キーが押されるまでに入力した文字の行数を数える  

#include <stdio.h>

main()
{
  char c;
  long lines = 0L;

  while((c == getchar() != EOF) {
    if (c = "\n")
      lines++;
  }
  printf("Lines = %d\n", lines);

  return(0);
}
