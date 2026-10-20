#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *in_file;     // 入力ファイルのファイルポインタ
  FILE *out_file;    // 出力ファイルのファイルポインタ
  int num;           // データの読み込み用;
  char buff[256];    // 入力用バッファ変数

  // 入力ファイル(テキスト)のオープン
  in_file = fopen("number.txt", "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  // 出力ファイル(バイナリ)のオープン
  out_file = fopen("number.bin", "w");
  // エラー処理
  if(out_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    fclose(in_file); // 入力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  // データを読み込み
  while(fgets(buff, sizeof(buff), in_file) != NULL){
    sscanf(buff, "%d", &num);
    // データをバイナリで書き込み
    fwrite(&num, sizeof(int), 1, out_file);
  }

  // エラー処理
  if(ferror(in_file)){
    fprintf(stderr, "number.txtの読み込み中にエラーが発生しました。\n");
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }
  if(ferror(out_file)){
    fprintf(stderr, "number.binの書き込み中にエラーが発生しました。\n");
    // ファイルのクローズ
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  fclose(in_file);    // 入力ファイルのクローズ
  fclose(out_file);   // 出力ファイルのクローズ

  return 0;
}
