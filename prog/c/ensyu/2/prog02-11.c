#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    float a[100], y;

    int i = n;
    while(i >= 0){
        printf("a[%d] = ",i);
        a[i] = getfloat("");
        i = i - 1;
    }

    float x = 1, X = 1;
    while(x != 0){
        x = getfloat("x: ");
        i = 0;
        y = 0;
        X = 1;
        while(i <= n){
            y = y + a[i] * X;
            X = X * x;
            i = i + 1;
        }
        printf("y = %g\n",y);
    }

    return (0);
}