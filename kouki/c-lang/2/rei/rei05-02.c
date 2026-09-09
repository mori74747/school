#include <stdio.h>

main()
{
  int Taro, Hanako, Jiro;
  Taro   = 20;     // 太郎の年齢 
  Hanako = 30;     // 花子の年齢 
  Jiro   = 10;     // 次郎の年齢 

  // 変数と定数の比較 
  if (Taro == 20) {
    printf("太郎は20歳です。\n");
  }
  if (Hanako != 20) {
    printf("花子は20歳ではありません。\n");
  }
  if (Hanako >= 20) {
    printf("花子は20歳以上です。\n");
  }
  if (Jiro < 20) {
    printf("次郎は20歳未満です。\n");
  }
  // 変数と変数の比較 
  if (Taro > Jiro) {
    printf("太郎は次郎より年上です。\n");
  }
  if (Taro < Hanako) {
    printf("太郎は花子より年下です。\n");
  }
  return(0);
}
