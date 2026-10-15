
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char *argv[])
{
  FILE *in_file;
  FILE *out_file;
  char buff[256];

  int append = 0;
  char *file1;
  char *file2;

  // オプションの確認
  if(argc == 3){
    file1 = argv[1];
    file2 = argv[2];
  }else if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'a'){
    append = 1;
    file1 = argv[2];
    file2 = argv[3];
  }else{
    printf("不正な入力です。\n");
    return (2);
  }

  // 入力ファイルを開く
  in_file = fopen(file1, "r");
  if(in_file == NULL){
    printf("%sがオープンできませんでした。\n", file1);
    return 2;
  }

  // 出力ファイルを開く
  if(append == 1){
    out_file = fopen(file2, "a");
  }else{
    out_file = fopen(file2, "w");
  }

  if(out_file == NULL){
    printf("%sがオープンできませんでした。\n", file2);
    fclose(in_file);
    return (2);
  }

  // 入力ファイルから読み込み、出力ファイルへ書き込む
  while(fgets(buff, sizeof(buff), in_file) != NULL){
    fputs(buff, out_file);
  }

  // ファイルを閉じる
  fclose(in_file);
  fclose(out_file);

  return (0);
}
