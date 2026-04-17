#include <stdio.h>   //  ファイルに関して定義されているヘッダファイル  
#include <stdlib.h>

int main()
{
  FILE *in_file;  //  入力ファイルへのファイルポインタ  
  char buff[256]; //  入力データを一時格納する変数  
  char *in_filename = "alice.txt"; //  データを入力するファイル  

  in_file  =  fopen(in_filename, "r"); //  入力ファイルのオープン  
  if (in_file == NULL)  {
    printf("%sがオープンできませんでした。\n", in_filename);
    exit(8); //  異常終了である非ゼロを返してプログラム終了  
  }

  printf("%sの内容\n", in_filename);
  //  エラーを検出するか、ファイルの終わりに達するまで入力を続ける  
  while (fgets(buff, sizeof(buff), in_file) != NULL) {
    fputs(buff, stdout); //  標準出力へ出力  
  }
  fclose(in_file); //  入力ファイルのクローズ  

  return(0);
}
