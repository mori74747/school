
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char *argv[])
{
  FILE *in_file;    // 入力ファイルのファイルポインタ
  FILE *out_file;   // 出力ファイルのファイルポインタ
  char buff[256];   // 入力用バッファ

  int append = 0;   // 追記するかどうかを表す (追記する...1/上書き...0)
  char *file1;      // コピー元ファイル名
  char *file2;      // コピー先ファイル名

  // オプションの確認
  if(argc == 3){
    file1 = argv[1];
    file2 = argv[2];
  }else if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'a'){
    append = 1;
    file1 = argv[2];
    file2 = argv[3];
  }else{
    // エラー処理
    fprintf(stderr, "不正な入力です。\n");
    exit(2);
  }

  // 入力ファイルを開く
  in_file = fopen(file1, "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "%sがオープンできませんでした。\n", file1);
    exit(2);
  }

  // 出力ファイルを開く
  if(append == 1){
    out_file = fopen(file2, "a");
  }else{
    out_file = fopen(file2, "w");
  }

  // エラー処理
  if(out_file == NULL){
    fprintf(stderr, "%sがオープンできませんでした。\n", file2);
    fclose(in_file);
    exit (2);
  }

  // 入力ファイルから読み込み、出力ファイルへ書き込む
  while(fgets(buff, sizeof(buff), in_file) != NULL){
    fputs(buff, out_file);
  }

  // ファイルのクローズ
  fclose(in_file);
  fclose(out_file);

  return (0);
}
