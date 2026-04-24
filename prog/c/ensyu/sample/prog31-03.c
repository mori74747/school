#include <stdio.h>
#include <stdlib.h>

unsigned int  bit2int(char *bit, unsigned int dec);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "２進整数を引数に指定してください。\n");
    exit(1);
  }
  printf("%u\n", bit2int(       ,   )); // 符号なし10進数を表示

  return(0);
}

// dec は 2進数文字列 bit を符号なし10進数に変換した値
unsigned int bit2int(char *bit, unsigned int dec)
{

}
