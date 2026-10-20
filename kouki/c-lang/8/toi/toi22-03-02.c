#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *in_file;     // 入力ファイルのファイルポインタ
  FILE *out_file;    // 出力ファイルのファイルポインタ
  int num;           // データの読み込み用

  // 入力ファイル(バイナリ)のオープン
  in_file = fopen("number.bin", "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2);
  }

  // 出力ファイル(テキスト)のオープン
  out_file = fopen("rebmun.txt", "w");
  // エラー処理
  if(out_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    fclose(in_file);
    exit(2);
  }

  // バイナリデータの読み込み
  while(fread(&num, sizeof(int), 1, in_file)){
    // データをfile2へ書き込み
    fprintf(out_file, "%d\n", num);
  }

  // エラー処理
  if(ferror(in_file)){
    fprintf(stderr, "number.binの読み込み中にエラーが発生しました。\n");
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }
  if(ferror(out_file)){
    fprintf(stderr, "rebmun.txtの書き込み中にエラーが発生しました。\n");
    // ファイルのクローズ
    fclose(in_file);    // 入力ファイルのクローズ
    fclose(out_file);   // 出力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  fclose(in_file);    // 入力ファイルのクローズ
  fclose(out_file);   // 出力ファイルのクローズ

  return (0);
}
