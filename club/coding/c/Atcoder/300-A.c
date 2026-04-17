//A - N-choice question 

#include <stdio.h>

int main(){

    int A, B, N, i;

    scanf("%d%d%d",&N,&A,&B);

    int C[N];

    for(i = 0;i < N;i++){

        scanf("%d",&C[i]);
    }
    for(i = 0;i < N;i++){

        if(A + B == C[i]){
            printf("%d\n",i + 1);
        }
    }
    return 0;
}