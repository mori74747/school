#include <stdio.h>   //  ファイルに関して定義されているヘッダファイル  
#include <stdlib.h>

int main()
{
  FILE *in_file;  //  入力ファイルへのファイルポインタ  
  int  ch;        //  データを入力する変数  
  char *filename = "alice.txt";   //  データを入力するファイル  

  in_file = fopen(filename, "r"); //  ファイルのオープン  
  if (in_file == NULL) {
    printf("%sがオープンできませんでした。\n", filename);
    exit(8); //  異常終了である非ゼロを返してプログラム終了  
  }
  //  エラーを検出するか、ファイルの終わりに達するまで入力を続ける  
  while ((ch = fgetc(in_file)) != EOF) {
    fputc(ch, stdout); //  putchar(ch); と同じ  
  }
  fclose(in_file); //  ファイルのクローズ  

  return(0);
}
