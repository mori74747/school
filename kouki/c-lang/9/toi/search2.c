#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <hamakou.h>
#include "allocwords.h" 

int main(int argc, char *argv[]) 
{ 
  int n; 
  char **p;

  // 行数の入力
  n = getint("行数の入力: ");

  if ((p = allocWords(&n)) == NULL) { 
    fprintf(stderr, "words allocation failed.╲n"); 
    exit(8); 
  }

  //p[] の各文字列に対して探索 
  
  freeWords(p, n);
  
  return(0); 
}