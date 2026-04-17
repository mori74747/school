#include <stdio.h>

int main(){

    int N,Q;
    scanf("%d\n",&N);

    int A[N];
    for(int i = 0; i < N; i++){

        scanf("%d ",&A[i]);
    }
    scanf("%d\n",&Q);

    int X[Q],Y[Q];

    for(int i = 0; i < Q; i++){
        int ans = 0;

        scanf("%d%d",&X[i],&Y[i]);

        for(int j = 0; X[i] + j <= Y[i]; j++){

            ans += A[X[i]+j-1];
        }
        printf("%d\n",ans);
    }
    



    return 0;
}