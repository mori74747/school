#include <bits/stdc++.h>
using namespace std;
struct pairIC{
    double x1;
    double y1;
    double x2;
    double y2;
} ;

int main(){

    pairIC pea;
    cin >> pea.x1 >> pea.y1 >> pea.x2 >> pea.y2;

    if( pea.x1 < pea.x2){
        if( pea.y1 < pea.y2){
            printf("%.6lf %.6lf\n",pea.x2,pea.y1);
        }else{
            printf("%.6lf %.6lf\n",pea.x2,pea.y2);
        }

    }else{
        if( pea.y1 < pea.y2){
            printf("%.6lf %.6lf\n",pea.x1,pea.y1);
        }else{
            printf("%.6lf %.6lf\n",pea.x1,pea.y2);
        }

    }





    return 0;
}