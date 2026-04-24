#include <stdio.h>
#include <math.h>

typedef struct {
  double x; // x 座標 
  double y; // y 座標 
} Point;

typedef struct {
  Point p1; // 対角線を表す点1 
  Point p2; // 対角線を表す点2 
} Rect;

Point ptCreate(double x, double y);
double ptGetX(Point p);
double ptGetY(Point p);

double rctArea(Rect rct);
double rctPerim(Rect rct);
double rctWidth(Rect rct);
double rctHeight(Rect rct);
double rctDiaglen(Rect rct);
Point rctTopLeftCorner(Rect rct);
Rect rctCreate1(Point p1, Point p2);
Rect rctCreate2(Point p, double width, double height);

main()
{
  Rect r;
  Point p1, p2;
  double x1, y1, x2, y2, w, h, s;

  printf("長方形１\n");
  printf("対角線の端点1の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  printf("対角線の端点2の座標(x, y)："); scanf("%lg,%lg", &x2, &y2);
  p1 = ptCreate(x1, y1);
  p2 = ptCreate(x2, y2);

  r = rctCreate1(p1, p2); // 長方形の対角線を表す２点で初期化 
  putchar('\n');
  printf("左上隅の座標(x, y)：(%g, %g), ",                           ,                           );
  printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));
  putchar('\n');

  printf("長方形２\n");
  printf("左上の点の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
  p1 = ptCreate(x1, y1);
  printf("横："); scanf("%lg", &w);
  printf("縦："); scanf("%lg", &h);

  r = rctCreate2(p1, w, h); // 長方形の左上の点と、幅および高さで初期化 
  putchar('\n');
  printf("左上隅の座標(x, y)：(%g, %g), ",                           ,                           );
  printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));

  return(0);
}
