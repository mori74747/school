#include <stdio.h>
#include <stdlib.h>

main()
{
  FILE *file1, *file2;
  int num;

  file1 = fopen("number.txt", "r");
  if(file1 == NULL){
    fprintf(stderr, "ファイルを開けません。\n");
    exit (2);
  }

  file2 = fopen("number.bin", "wb");
  if(file2 == NULL){
    fprintf(stderr, "ファイルを作成できません。\n");
    fclose(file1);
    exit (2);
  }

  while(fscanf(file1, "%d", &num) == 1){
    fwrite(&num, sizeof(int), 1, file2);
  }

  fclose(file1);
  fclose(file2);

  return 0;
}
