#include <stdio.h>
#include <stdlib.h>
#include "hamakou.h"
#include <string.h>

main(){

  int n;          //  文字列の数
  char **p;       //  文字列
  
  char buff[256]; //  入力用バッファ文字列
  int i, j;       //  カウンタ変数


  n = getint("文字列の数 n: ");

  p = (char**)malloc(n * sizeof(char*));
  //  メモリ確保の失敗
  if(p == NULL){
    printf("メモリ確保エラー\n");
    return (1);
  }

  for(i = 0; i < n; i++){
    //  文字列の入力
    fgets(buff, sizeof(buff), stdin);
    //  改行文字の排除
    buff[strcspn(buff, "\n")] = '\0';
    //  文字列を動的に確保
    p[i] = (char*)malloc((strlen(buff)+1) * sizeof(char));
    //  メモリ確保の失敗
    if(p[i] == NULL){
      printf("メモリ確保エラー\n");
      //  既に確保したメモリの開放
      for(j = 0; j < i; j++){
        free(p[j]);
      }
      free(p);

      return (1);
    }
    //  文字列を確保したメモリに格納
    strcpy(p[i], buff);
  }

  for(i = 0; i < n; i++){
    printf("%s\n", p[i]);

    //  各文字列で確保したメモリを解放
    free(p[i]);
  }

  //  pのメモリの開放
  free(p);

  return (0);
}