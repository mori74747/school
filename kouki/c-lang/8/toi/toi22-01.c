#include <stdio.h>
#include <stdlib.h>

int main(int a, char *in_filename[])
{
  FILE *in_file;        // 入力ファイルへのファイルポインタ  
  char buff[256];       // 入力データを一時格納する変数  
  char ch;                

  int moji = 0;     // 文字数
  int n = 0;        // 行数
  
  in_file = fopen(in_filename[1], "r");   // 入力ファイルのオープン
  if (in_file == NULL)  {
    printf("%sがオープンできませんでした。\n", in_filename[1]);
    exit(2); // 異常終了である非ゼロを返してプログラム終了  
  }

  // エラーを検出するか、ファイルの終わりに達するまで入力を続ける  
  while ((ch = fgetc(in_file)) != EOF) {
    moji++;
    if(ch == '\n'){
      n++;  // 行数をカウント
    }
  }
  fclose(in_file); // 入力ファイルのクローズ  

  printf("文字数: %d\n", moji);
  printf("行数: %d\n", n);

  return(0);
}
