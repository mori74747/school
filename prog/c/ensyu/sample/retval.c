#include <stdio.h>

int main(int argc, char *argv[])
{
  unsigned int val = 0;

  if (argc > 1) {
    sscanf(argv[1], "%d", &val);
  }

  return(val);
}
