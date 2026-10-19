
#include <stdio.h>

int main(void)
{
  unsigned int num;
  unsigned int mask = 0x00000001;
  int count = 0;

  // 整数値を入力
  printf("整数値を入力してください：");
  scanf("%u", &num);

  // 最下位ビットから順番に調べる
  while(num != 0){
    if((num & mask) != 0){
      count++;
    }

    num >>= 1;
  }

  // カウントした結果を表示
  printf("1のビット数は %d です。\n", count);

  return 0;
}
