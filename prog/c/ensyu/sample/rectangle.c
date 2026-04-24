#include <stdio.h>
#include <math.h>

typedef struct {
  double x; /* x 座標 */
  double y; /* y 座標 */
} POINT;

typedef struct {
  POINT p1; /* 対角線を表す点1 */
  POINT p2; /* 対角線を表す点2 */
} RECT;

POINT ptSet(double x, double y);
double ptGetX(POINT p);
double ptGetY(POINT p);

RECT rctSet1(POINT p1, POINT p2);
RECT rctSet2(POINT p, double width, double height);
double rctArea(RECT rct);
double rctPerim(RECT rct);
double rctWidth(RECT rct);
double rctHeight(RECT rct);
double rctDiaglen(RECT rct);

main()
{
  RECT r;
  POINT p1, p2;
  double x1, y1, x2, y2, w, h, s;

  printf("対角線の端点1の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  printf("対角線の端点2の座標(x, y)："); scanf("%lg,%lg", &x2, &y2);
  p1 = ptSet(x1, y1);
  p2 = ptSet(x2, y2);

  r = rctSet1(p1, p2); /* 長方形の対角線を表す２点で初期化 */
  printf("面積：%g, 周囲：%g, 対角線長：%g\n\n", rctArea(r), rctPerim(r), rctDiaglen(r));

  printf("左上の点の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  p1 = ptSet(x1, y1);
  printf("横："); scanf("%lg", &w);
  printf("縦："); scanf("%lg", &h);
  r = rctSet2(p1, w, h); /* 長方形の左上の点と、幅および高さで初期化 */
  printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));

  return(0);
}
