#include <stdio.h>

main()
{
  // int i == 1;
  // iに1を代入するには "i = 1"と書く
  int i = 1;

  switch (i) {
    // case '1';
    // 場合分けは定数で表現するため、''(シングルクォーテーション)で囲まない
    // 場合訳の最後は";"セミコロンではなく、":"(コロン)をつける
    case 1:
      printf("i = 1\n");
      break; //caseの最後にはbreak; を入れる

    // case 2,
    // 場合分けの最後は":"を(コロン)つける
    case 2:
      printf("i = 2\n");
      break; //caseの最後にはbreak; を入れる

    // case3:
    // case と 定数との間は空白を入れる
    case 3:
      printf("i = 3\n");
      break; //caseの最後にはbreak; を入れる

    // default
    // 場合分けの最後には":"(コロン)を入れる
    default:

      // printf("error");
      // おそらく改行したほうが好ましい。よって"\n"を出力文字列の最後に入れる
      printf("error\n");

      //最後のbreakはおそらくどちらでもよい

  } // switch文の最後は、"}"でしっかり閉じる
  
  return(0);
}
