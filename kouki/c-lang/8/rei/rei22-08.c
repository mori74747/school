#include <stdio.h>

main()
{
  FILE *fp;
  int c;

  fp = fopen("test.dat", "r"); // "test.dat"を読み取り用でオープン 

  fputc(c, fp); // 読み取り用ファイルに書き込もうとした 
  if (ferror(fp)) {
    fprintf(stderr, "エラー\n");
    clearerr(fp);  // エラーを解除して 
    c = fgetc(fp); // 改めて入力       
    printf("入力した文字は%c\n", c);
  }
  fclose(fp);

  return(0);
}
