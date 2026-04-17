//1917 - 小学2年生のKamba君

#include <stdio.h>

int main() {

    int A, B, C;

    scanf("%d%d",&A,&B);

    C = A * B;

    if(A <= 9 && B <= 9) {

        printf("%d\n",C);
    } else {

        printf("%d\n", -1);
    }



    return 0;
}
