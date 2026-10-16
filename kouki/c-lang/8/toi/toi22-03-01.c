#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *fp;
  int i;

  fp = fopen("number.txt", "w");
  // 配列p[]から、POINT型データを10個"point.dat"に書き出す
  fread(p, sizeof(POINT), 10, fp);
  fclose(fp);

  return(0);
}
