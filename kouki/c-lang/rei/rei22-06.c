#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double x;
  double y;
} POINT;

int main()
{
  POINT p[10] = {{0.0, 0.0}, {0.0, 0.1}, {1.1, 1.2},
                 {2.2, 2.3}, {3.3, 3.4}, {4.4, 4.5},
                 {5.5, 5.6}, {6.6, 6.7}, {7.7, 7.8},
                 {8.8, 8.9}};
  POINT q[10];
  FILE *fp;
  int i;

  fp = fopen("point.dat", "w");
  // 配列p[]から、POINT型データを10個"point.dat"に書き出す
  fwrite(p, sizeof(POINT), 10, fp);
  fclose(fp);

  fp = fopen("point.dat", "r");
  // "point.dat"から、配列q[]にPOINT型データを10個読み込む
  fread(q, sizeof(POINT), 10, fp);
  fclose(fp);

  for (i = 0; i < 10; i++) {
    printf("(%g, %g)\n", q[i].x, q[i].y);
  }

  return(0);
}
