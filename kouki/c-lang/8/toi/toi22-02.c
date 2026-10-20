
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
  if(argc == 3){  // ファイルに上書きする
    file1 = argv[1];
    file2 = argv[2];
  }else if(argc == 4 && argv[1][0] == '-' && argv[1][1] == 'a'){  // ファイルに追記する
    append = 1;  
    file1 = argv[2];
    file2 = argv[3];
  }else{
    // エラー処理
    fprintf(stderr, "不正な入力です。\n");
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  in_file = fopen(file1, "r");  // 入力ファイルのオープン
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "%sがオープンできませんでした。\n", file1);
    exit(2); // 異常終了である非ゼロを返してプログラム終了
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
    exit (2); // 異常終了である非ゼロを返してプログラム終了
  }

  // 入力ファイルから読み込み、出力ファイルへ書き込む
  while(fgets(buff, sizeof(buff), in_file) != NULL && fputs(buff, out_file) != EOF);

  // エラー処理
  if(ferror(in_file)){
    fprintf(stderr, "%sの読み込み中にエラーが発生しました。\n", file1);
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }
  if(ferror(out_file)){
    fprintf(stderr, "%sの書き込み中にエラーが発生しました。\n", file2);
    // ファイルのクローズ
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  fclose(in_file);    // 入力ファイルのクローズ
  fclose(out_file);   // 出力ファイルのクローズ

  return (0);
}
