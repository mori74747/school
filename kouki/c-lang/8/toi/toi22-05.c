#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
  FILE *in_file;            // 入力ファイルのファイルポインタ
  unsigned char data[16];   // 読みこんっだデータを16バイト保存
  size_t n;                 // 今回読み込んだバイト数
  int i;                    // カウンタ変数
  unsigned long addr = 0;   // 表示するデータの先頭アドレス

  // エラー処理
  if(argc != 2){
    fprintf(stderr, "不正な入力です。\n");
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  // 入力ファイルのオープン
  in_file = fopen(argv[1], "r");
  // エラー処理
  if(in_file == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  // 表示
  printf("%s%2s", "addr","");
  for(i = 0; i < 16; i++){
    printf(" +%X", i);
  }
  printf("%8s%s", "","キャラクタ\n");

  // 16バイトずつ読み込み→1文字ずつ表示
  while((n = fread(data, 1, 16, in_file)) > 0){
    printf("%04lX%3s", addr, "");

    // アドレスの表示
    for(i = 0; i < 16; i++){
      if(i < n){
        printf("%02X ", data[i]);
      }else{
        printf("%3s","");
      }
    }
    printf("%3s", "");

    // アドレスを文字で表示
    for(i = 0; i < (int)n; i++){
      if(' ' <= data[i] && data[i] <= '~'){
        printf("%c", data[i]);
      }else{
        printf(".");
      }
    }

    putchar('\n');
    addr += 16;
  }

  // エラー処理
  if(ferror(in_file)){
    fprintf(stderr, "\n%sの読み込み中にエラーが発生しました。\n", argv[1]);
    fclose(in_file);    // 入力ファイルのクローズ
    exit(2); // 異常終了である非ゼロを返してプログラム終了
  }

  fclose(in_file); // 入力ファイルのクローズ

  return (0);
}
