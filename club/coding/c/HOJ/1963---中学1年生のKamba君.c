//1963 - 中学1年生のKamba君

#include <stdio.h>

int main() {


    int A, B, M;

    scanf("%d%d",&A,&B);

    while(A != (0)){

        M = A + B;

        printf("%d\n",M);

        scanf("%d%d",&A,&B);
    }

    return 0;
}