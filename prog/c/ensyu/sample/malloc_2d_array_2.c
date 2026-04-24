#include <stdio.h>
#include <stdlib.h>
#include <hamakou.h>

main()
{
  int M, N, i, j, **p;

  M = getint("行の数: ");
  N = getint("列の数: ");

  p = (int **)malloc(sizeof(int *) * M);
  for (i = 0; i < M; i++) {
    p[i] = (int *)malloc(sizeof(int) * N);
  }

  for (i = 0; i < M; i++) {
    for (j = 0; j < N; j++) {
      p[i][j] = (i + 1) * (j + 1);
      printf("%4d", p[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < M; i++) {
    free(p[i]);
  }
  free(p);

  return(0);
}
