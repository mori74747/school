//007-Ave
//後付け
#include <stdio.h>

int main(){

    int N, i;

    scanf("%d",&N);

    int A[N];
    float ans, total = 0;

    for(i = 0; i < N; i++){

        scanf("%d",&A[i]);

        total += A[i];
    }

    ans = total / N;

    printf("%.2f\n",ans);

    return 0;
}