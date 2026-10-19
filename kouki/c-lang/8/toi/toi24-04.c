#include <stdio.h>

main()
{
  unsigned int num;                 // 入力する整数値
  unsigned int mask = 0x00000001;   // マスク
  int count = 0;                    // 1のビットを数えるカウンタ変数

  // 整数値を入力
  printf("整数値を入力してください: ");
  scanf("%u", &num);

  // 最下位ビットから順番に調べる
  while(num != 0){  // 整数値が最上位bitからシフトされるまで
    if((num & mask) == 1){  // 1のビットを発見
      count++;  
    }
    num >>= 1;    // 整数値のシフト
  }

  // カウントした結果を表示
  printf("1のビット数: %d\n", count);

  return (0);
}