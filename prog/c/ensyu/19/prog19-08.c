#include <stdio.h>
#include <math.h>

typedef struct {
    double p[2]; // p[0]: x座標, p[1]: y座標
} Point;

typedef struct {
    Point p1; // 対角線を表す点1 
    Point p2; // 対角線を表す点2 
} Rect;

double ptGetX(Point p);
double ptGetY(Point p);
Point ptCreate(double x, double y);

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
    printf("左上隅の座標(x, y)：(%g, %g), ", ptGetX(rctTopLeftCorner(r)), ptGetY(rctTopLeftCorner(r)));
    printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));
    putchar('\n');

    printf("長方形２\n");
    printf("左上の点の座標(x, y)："); scanf("%lg,%lg", &x1, &y1);
    p1 = ptCreate(x1, y1);
    printf("横："); scanf("%lg", &w);
    printf("縦："); scanf("%lg", &h);

    r = rctCreate2(p1, w, h); // 長方形の左上の点と、幅および高さで初期化 
    putchar('\n');
    printf("左上隅の座標(x, y)：(%g, %g), ", ptGetX(rctTopLeftCorner(r)), ptGetY(rctTopLeftCorner(r)));
    printf("面積：%g, 周囲：%g, 対角線長：%g\n", rctArea(r), rctPerim(r), rctDiaglen(r));

    return(0);
}

// point型の操作関数

// 点pのx座標を返す
// [引　数] Point型 : p
// [戻り値] double型: 点pのx座標
double ptGetX(Point p){
    return(p.p[0]);
}

// 点pのy座標を返す
// [引　数] Point型 : p
// [戻り値] double型: 点pのy座標
double ptGetY(Point p){
    return(p.p[1]);
}

// 座標(x, y)の点を生成する
// [引　数] double型: x, y
// [戻り値] Point型 : 座標(x, y)の点
Point ptCreate(double x, double y){
    Point z;
    z.p[0] = x;
    z.p[1] = y;

    return(z);
}

// Rect型の操作関数

// 長方形rctの面積を返す
// [引　数] Rect型  : 長方形rct
// [戻り値] double型: 長方形rctの面積
double rctArea(Rect rct){
    return(rctWidth(rct) * rctHeight(rct));
}

// 長方形rctの周囲の長さを返す
// [引　数] Rect型  : 長方形rct
// [戻り値] double型: 長方形rctの周囲の長さ
double rctPerim(Rect rct){
    return((rctWidth(rct) + rctHeight(rct)) * 2);
}

// 長方形rctの幅(横)の長さを返す
// [引　数] Rect型  : 長方形rct
// [戻り値] double型: 長方形rctの幅(横)の長さ
double rctWidth(Rect rct){
    return(fabs(ptGetX(rct.p1) - ptGetX(rct.p2)));
}

// 長方形rctの高さ(縦)の長さを返す
// [引　数] Rect型  : 長方形rct
// [戻り値] double型: 長方形rctの高さ(縦)の長さ
double rctHeight(Rect rct){
    return(fabs(ptGetY(rct.p1) - ptGetY(rct.p2)));
}

// 長方形rctの対角線の長さを返す
// [引　数] Rect型  : 長方形rct
// [戻り値] double型: 長方形rctの対角線の長さ
double rctDiaglen(Rect rct){
    return(sqrt(pow(rctWidth(rct), 2) + pow(rctHeight(rct), 2)));
}

// 長方形rctの左上隅の点を返す
// [引　数] Rect型  : 長方形rct
// [戻り値] Point型 : 長方形rctの左上隅の点
Point rctTopLeftCorner(Rect rct){
    double TopLeftPoint_x;
    double TopLeftPoint_y;
    double p1_x = ptGetX(rct.p1);
    double p1_y = ptGetY(rct.p1);
    double p2_x = ptGetX(rct.p2);
    double p2_y = ptGetY(rct.p2);
    if(p1_x < p2_x){
        TopLeftPoint_x = p1_x;
    }else{
        TopLeftPoint_x = p2_x;
    }
    if(p1_y < p2_y){
        TopLeftPoint_y = p2_y;
    }else{
        TopLeftPoint_y = p1_y;
    }
    return(ptCreate(TopLeftPoint_x, TopLeftPoint_y));
}

// 対角線を表す2点p1とp2から、長方形を生成する
// [引　数] Point型 : 対角線を表す p1, p2
// [戻り値] Rect型  : p1とp2が対角線上にある長方形
Rect rctCreate1(Point p1, Point p2){
    Rect z;
    z.p1 = p1;
    z.p2 = p2;

    return (z);
}

// 左上隅の1点pと、幅(横)widthおよび高さ(縦)heightの長さから、長方形を生成する
// [引　数] Point型 : 左上隅の点p ,
//  　　　  double型: 幅(横)の長さwidth, 高さ(縦)の長さheight
// [戻り値] Rect型  : p1とp2が対角線上にある長方形
Rect rctCreate2(Point p, double width, double height){
    
    Point p1 = p;
    Point p2 = ptCreate(ptGetX(p) + width, ptGetY(p) - height);

    return(rctCreate1(p1, p2));
}

