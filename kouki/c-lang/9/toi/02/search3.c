#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocwords.h"

int main(int argc, char *argv[]){

  char **lines;       // 文字列配列
  int line_nums;      // 文字列の行数
  int i;              // 探索位置

  // コマンドライン引数の確認
  if(argc != 2){
    fprintf(stderr, "Usage: %s <文字列>\n", argv[0]);
    exit(2);
  }

  // 文字列を読み込む
  lines = allocWords(&line_nums);

  // メモリ確保・入力失敗の確認
  if(lines == NULL){
    exit(2);
  }

  // 番兵を設定
  lines[line_nums] = argv[1];
  // 線形探索（番兵あり）
  for(i = 0; strcmp(lines[i], argv[1]) != 0; i++);
  
  // 探索結果の表示
  if(i < line_nums){
    printf("line %d: '%s' found.\n", i + 1, argv[1]);
  }else{
    printf("'%s' dose not found.\n", argv[1]);
  }

  // メモリの解放
  freeWords(lines, line_nums);

  return (0);
}
