// Atcoder Problem

#include <stdio.h>

int main(){

    int N, M, i,ANS=0;

    scanf("%d%d",&N,&M);

    int A[N], B[M];

    for(i = 0; i < N; i++){

        scanf("%d",&A[i]);
    }

    for(i = 0; i < M; i++){

        scanf("%d",&B[i]);
    }

    for(i = 0; i < M; i++){

            ANS += A[B[i]-1];
    }

    printf("%d\n",ANS);



    return 0;
}