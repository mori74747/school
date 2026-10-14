#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *fp;
  int c;

  fp = fopen("test.dat", "r");
  if (fp == NULL) { // 注意：fopen()のエラーはferror()では検出できない 
    fprintf(stderr, "ファイルオープンエラー\n");
    exit(8);
  }
  while(1) {
    c = fgetc(fp);
    if (feof(fp)) {
      fprintf(stderr, "ファイル終了\n");
      fclose(fp);
      exit(0);
    } else if (ferror(fp)) {
      fprintf(stderr, "読み取りエラー\n");
      fclose(fp);
      exit(8);
    }
    fputc(c, stdout);
  }

  return(0);
}
