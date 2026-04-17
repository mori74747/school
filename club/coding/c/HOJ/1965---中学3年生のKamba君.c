//1965 - 中学3年生のKamba君

#include <stdio.h>

int main() {

    double A, B, X, Y;

    scanf("%lf%lf",&A,&B);

    X = A - B;

    if(X < 0){

        X = -X;
        //  X *= -1;  Ei科ではこれはださいらしいです
    }

    Y = X / B;

    printf("%.6lf\n",X);
    printf("%.6lf\n",Y);

    return 0;
}