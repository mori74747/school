#include <stdio.h>
#include <stdlib.h>

int sankaku(int n);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に正数nを指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%d\n", sankaku(n));

  return(0);
}

int sankaku(int n)
{

}
