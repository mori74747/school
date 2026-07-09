#include <stdio.h>
#include <hamakou.h>

typedef struct {
    double x;
    double y;
} Point;

void Point_SetX(Point *pt , double x);
void Point_SetY(Point *pt , double y);
double Point_GetX(Point *pt);
double Point_GetY(Point *pt);
Point Point_Create(double x, double y);

int main() {
    double x,y;
    Point myPoint;

    x = getfloat("x : ");
    y = getfloat("y : ");

    myPoint = Point_Create(x, y);
    printf("myPoint: x = %.1f, y = %.1f\n", Point_GetX(&myPoint), Point_GetY(&myPoint));

    return(0);
}

// アクセサー（Setter）の実装
void Point_SetX(Point *pt, double x) {
    pt->x = x;
    return;
}

void Point_SetY(Point *pt, double y) {
    pt->y = y;
    return;
}

// アクセサー（Getter）の実装
double Point_GetX(Point *pt) {
    return pt->x;
}

double Point_GetY(Point *pt) {
    return pt->y;
}

// コンストラクターの実装（セッターを使用）
Point Point_Create(double x, double y) {
    Point p;
    Point_SetX(&p, x);
    Point_SetY(&p, y);
    return p;
}
