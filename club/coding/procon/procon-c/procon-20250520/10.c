// 010 - abs

#include <stdio.h>

int main(){

    int i, N, ans;

    scanf("%d",&N);

    int A[N], B[N];

    for(i = 0; i < N; i++){

        scanf("%d%d", &A[i], &B[i]);
    }
    for(i = 0; i < N; i++){

        ans = A[i] - B[i];
    
        if(ans < 0){

            ans *= -1;
        }
        printf("%d\n",ans);
    }


    return 0;
}