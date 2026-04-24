#include <stdio.h>
#include <stdlib.h>

int sankaku(int n, int s);

int main(int argc, char *argv[])
{
  int n;

  if (argc < 2) {
    fprintf(stderr, "引数に正数nを指定してください。\n");
    exit(1);
  }
  sscanf(argv[1], "%d", &n);

  printf("%d\n", sankaku(  ,  ));

  return(0);
}

// s は第n項の三角数
int sankaku(int n, int s)
{

}
