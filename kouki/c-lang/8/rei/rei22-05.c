#include <stdio.h>

main()
{
  int n = 0;
  char s[256];

  while (n == 0) {
    printf("n = ");
    fgets(s, sizeof(s), stdin); // 文字列として入力 
    sscanf(s, "%d", &n);        // 文字列sに対して%d変換 
  }
}
