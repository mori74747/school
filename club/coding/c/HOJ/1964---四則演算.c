//1964 - 四則演算

#include <stdio.h>

int main() {

    int A, B, w, x, y, z;

    scanf("%d%d",&A,&B);

    w = A + B;
    x = A - B;
    y = A * B;
    z = A / B;

    printf("%d\n",w);
    printf("%d\n",x);
    printf("%d\n",y);
    printf("%d\n",z);

    return 0;
}