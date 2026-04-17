//B - Who is missing?

#include <stdio.h>

int main(){

    int N, M, i, B, ans;

    scanf("%d",&N);

    B = N * 4 -1;

    int A[B];
    M = 0;

    for(i = 0; i < B; i++){

        scanf("%d",&A[i]);
    }
    for(i = 0; i < B; i++){

        M += A[i];
    }
    for(i = 1; i <= N; i++){

        M -= (i * 4);
    }
    ans = M;
    ans *= -1;

    printf("%d\n",ans);


    return 0;
}