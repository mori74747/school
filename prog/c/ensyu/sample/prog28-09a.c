#include <stdio.h>
#include <stdlib.h>

void printBinary(int d);

int main(int argc, char *argv[])
{
  int d;

  if (argc < 2) {
    fprintf(stderr, "10進整数を引数に指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &d);

  printBinary(d);
  putchar('\n');

  return(0);
}

void printBinary(int d)
{

}
