//006-Positive Number

#include <stdio.h>

int main(){

    int N, i, ans = 0;

    scanf("%d",&N);

    int A[N];

    for(i = 0; i < N; i++){

        scanf("%d",&A[i]);
    }
    for(i = 0; i < N; i++){

        if(A[i] > 0){

            ans += A[i];
        }
    }
    printf("%d\n",ans);

    return 0;
}