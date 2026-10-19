#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *in_file;     // 入力ファイルのファイルポインタ
  FILE *out_file;    // 出力ファイルのファイルポインタ
  int num;           // データの読み込み用;

  // 入力ファイル(テキスト)のオープン
  in_file = fopen("number.txt", "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2);
  }

  // 出力ファイル(バイナリ)のオープン
  out_file = fopen("number.bin", "w");
  // エラー処理
  if(out_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    fclose(in_file);
    exit(2);
  }

  // データを読み込み
  while(fscanf(in_file, "%d", &num) == 1){
    // データをバイナリで書き込み
    fwrite(&num, sizeof(int), 1, out_file);
  }

  // ファイルのクローズ
  fclose(in_file);
  fclose(out_file);

  return 0;
}
