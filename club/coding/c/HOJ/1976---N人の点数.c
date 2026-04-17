//1976 - N人の点数

#include <stdio.h>

int main(){

    int N;

    scanf("%d",&N);

    int  A[N],i;

    for(i=0; i < N; i++){

        scanf("%d",&A[i]);
    }   

    for(i=N-1; i >= 0; i--){

        printf("%d\n",A[i]);
    }

    return 0;
}