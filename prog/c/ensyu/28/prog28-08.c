#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocWords(int *line_nums);
void freeWords(char **lines, int line_nums);
int rbSearch(char *target, char *words[], int n);
int rbSearchRec(char *target, char *words[], int lower, int upper);

main(int argc, char *argv[])
{
  int pos, n;
  char **words;

  if (argc < 2) {
    fprintf(stderr, "検索する単語をコマンドライン引数で指定してください。\n");
    exit(1);
  }
  words = allocWords(&n);  // 単語データを動的領域に読み込む

  pos = rbSearch(argv[1], words, n);
  printf("Found: %d\n", pos);

  freeWords(words, n);	   // allocWords()で確保した領域を開放する

  return(0);
}

int rbSearch(char *target, char *words[], int n)
{
  return(rbSearchRec(target, words, 0, n - 1));
}

int rbSearchRec(char *target, char *words[], int lower, int upper)
{
  if(lower > upper){
    return (-1);
  }
  int mid = (lower + upper) / 2;

  if(strcmp(words[mid], target) == 0){
    return (mid);
  }else if(strcmp(words[mid], target) < 0){
    return (rbSearchRec(target, words, mid+1, upper));
  }else{
    return (rbSearchRec(target, words, lower, mid-1));
  }
}

// --------------------------------------------------------------------------
//  arrocWords() と freeWords() の外部仕様は
//  Cマスター9 [探索] の課題A(1) で実装したものと同じ
// --------------------------------------------------------------------------

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
  char *line;      // 確保するときのポインタ
  int n;           // 入力する文字列の数

  *line_nums = 0;  // 入力できた数
  line = NULL;

  // 入力-エラー処理
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

  // エラー処理
  if(p == NULL){
    fprintf(stderr, "error: メモリの確保に失敗しました\n");
    return (NULL);
  }

  // 文字列を1行ずつ入力
  do {
    if(*line_nums < n && fgets(buff, sizeof(buff), stdin) != NULL){

      // 改行文字を取り除く
      buff[strcspn(buff, "\n")] = '\0';
      // 文字列用のメモリ確保
      line = (char *)malloc(strlen(buff) + 1);

      if(line != NULL){
        p[*line_nums] = line;
        // 文字列をコピー
        strcpy(p[*line_nums], buff);
        // 入力行数を増やす
        (*line_nums)++;

      }else{
        fprintf(stderr, "error: メモリの確保に失敗しました\n");
      }
    }else{
      line = NULL;
    }

  } while(*line_nums < n && line != NULL);

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
