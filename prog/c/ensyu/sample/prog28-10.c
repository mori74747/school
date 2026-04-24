//
//  分割数（整数ｎを正の数の和で表す）
//
#include <stdio.h>
#include <stdlib.h>

int partitionNumber(int n);
int partitionNumberRec(int n, int a);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "整数を引数に指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%d\n", partitionNumber(n));

  return(0);
}

int partitionNumber(int n)
{
  return(partitionNumberRec(n, n));  // nをn以下の数の和で表す
}

// nをa以下の数の和で表す
int partitionNumberRec(int n, int a)
{

}
