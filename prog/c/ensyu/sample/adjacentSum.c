#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void showData(int data[], int n);

int main(int argc, char *argv[])
{
  int n, rank, numprocs, i, sum, temp, *p, *data, *result;
  int start, end;

  n = SIZE;

  p = (int *)malloc((sizeof(int) + 2) * SIZE);
  result = (int *)malloc(sizeof(int) * SIZE);
  
  data = p + 1;
  for (i = 0; i < n; i++) {
    data[i] = i + 1;
  }
  data[-1] = 0; data[n] = 0;
  showData(data, n);

  for (i = 0; i < n; i++) {
    result[i] = data[i - 1] + data[i] + data[i + 1];
  }
  showData(result, n);

  return(0);
}

void showData(int data[], int n)
{
  int i;

  for (i = 0; i < n; i++) {
    printf("%d ", data[i]);
  }
  printf("\n");
}
