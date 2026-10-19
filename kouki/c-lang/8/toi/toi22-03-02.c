#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *file1, *file2;
  int num;

  file1 = fopen("number.bin", "r");
  if(file1 == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit (2);
  }

  file2 = fopen("rebmun.txt", "wb");
  if(file2 == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    fclose(file1);
    exit (2);
  }

  while(fread(&num, sizeof(int), 1, file1)){
    fprintf(file2, "%d\n", num);
  }

  fclose(file1);
  fclose(file2);

  return 0;
}
