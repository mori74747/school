#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocwords.h"

/*-----------------------------------------------------------------------------------------------
［引 数］
    入力した文字列の行数を格納する変数へのポインタ 
［戻り値］
    入力行を正常に確保できた   ： 全入力行を格納した配列へのポインタ 
    入力行の領域確保に失敗した ： NULL 
［機 能］
    標準入力より文字列を行単位で入力し、上図の構造を動的に作る。
    すべて の文字列が正常に入力できたとき、*line_nums には入力した文字列の行数が入る。
    入力行の領域確保に失敗したときは、*line_nums は 0 になる。
-----------------------------------------------------------------------------------------------*/
char **allocWords(int *line_nums){
  char buff[257];  // 入力用バッファ
  char **p;        // 文字列配列へのポインタ
  int n;           // 入力する文字列の数

  *line_nums = 0;

  if(fgets(buff, sizeof(buff), stdin) == NULL){
    return (NULL);
  }
  if(sscanf(buff, "%d", &n) != 1){
    return (NULL);
  }
  // 行数のチェック
  if(n < 0){
    return (NULL);
  }

  // ポインタ配列のメモリ確保
  p = (char **)malloc(sizeof(char *) * (n + 1));

  if(p == NULL){
    fprintf(stderr, "error: メモリの確保に失敗しました\n");
    return (NULL);
  }

  // 文字列を1行ずつ入力
  while(*line_nums < n && fgets(buff, sizeof(buff), stdin) != NULL){
    // 改行文字を取り除く
    buff[strcspn(buff, "\n")] = '\0';
    // 文字列用のメモリ確保
    p[*line_nums] = (char *)malloc(sizeof(char) * (strlen(buff) + 1));

    // メモリ確保失敗時
    if(p[*line_nums] == NULL){
      fprintf(stderr, "error: メモリの確保に失敗しました\n");

      // 確保済みの文字列を解放
      freeWords(p, *line_nums);

      return (NULL);
    }
    // 文字列をコピー
    strcpy(p[*line_nums], buff);
    // 入力行数を増やす
    (*line_nums)++;
  }

  // すべての文字列が入力できたか確認
  if(*line_nums < n){
    // 確保済みの文字列を解放
    freeWords(p, *line_nums);

    return (NULL);
  }

  // 配列の最後にNULLを格納
  p[*line_nums] = NULL;

  return (p);
}


/*-----------------------------------------------------------------------------------------------
［引 数］
    lines ： allocWords()で入力した全文字列を格納している配列への ポインタ 
    line_nums： linesに格納されている文字列の行数 
［戻り値］なし 
［機 能］allocWords()で確保した領域をすべて解放する
-----------------------------------------------------------------------------------------------*/
void freeWords(char **lines, int line_nums){
  // 各文字列のメモリを解放
  for(int i = 0; i < line_nums; i++){
      free(lines[i]);
  }
  // ポインタ配列のメモリを解放
  free(lines);

  return;
}
