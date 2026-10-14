#include <stdio.h>
#include <stdlib.h>

int main(int a, char *in_filename[])
{
  FILE *in_file;        // 入力ファイルへのファイルポインタ  
  char buff[256];       // 入力データを一時格納する変数  

  

  if(in_filename[1][0] == '-'){     // オプションがある
    if(in_filename[1][1] != 'a'){
      printf("不正なオプション\n");
    }else{
      in_file = fopen(in_filename[2], "w");

      if (in_file == NULL)  {
        printf("%sがオープンできませんでした。\n", in_filename[2]);
        exit(2); // 異常終了である非ゼロを返してプログラム終了  
      }


    }
  }else{                            // オプションがない
    in_file = fopen(in_filename[2], "a");

    if (in_file == NULL)  {
      printf("%sがオープンできませんでした。\n", in_filename[2]);
      exit(2); // 異常終了である非ゼロを返してプログラム終了  
    }


  }
  
  return(0);
}
