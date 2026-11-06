#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hamakou.h>

void rotate(char *word, int n);
void anagram(char *word, int n);

main(int argc, char *argv[])
{
  int pos, n;
  char *word;

  if (argc < 2) {
    fprintf(stderr, "アナグラムを作る文字列をコマンドライン引数で指定して下さい。\n");
    exit(1);
  }
  word = argv[1];
  anagram(word, strlen(word));

  return(0);
}

// 文字列wordの右からn文字分を左回りで1文字回転させる
void rotate(char *word, int n)
{

}

void anagram(char *word, int n)
{

}
