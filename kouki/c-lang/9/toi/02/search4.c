#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocwords.h"

int main(int argc, char *argv[]){

  char **lines;       // 文字列配列
  int line_nums;      // 文字列の行数
  int result = -1;    // 探索結果
  int low, high, mid; // 二分探索用変数  

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

  // 二分探索の初期設定
  low = 0;
  high = line_nums - 1;

  // 二分探索
  while(low <= high){
    mid = (low + high) / 2;

    if(strcmp(lines[mid], argv[1]) == 0){
      result = mid;
    }else if(strcmp(lines[mid], argv[1]) < 0){
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }

  // 探索結果の表示
  if(result != -1){
    printf("line %d: '%s' found.\n", result + 1, argv[1]);
  }else{
    printf("'%s' dose not found.\n", argv[1]);
  }

  // メモリの解放
  freeWords(lines, line_nums);

  return (0);
}