#include <stdio.h>

int main(){

    int N;
    scanf("%d",&N);
    int A[N];

    for(int i = 2; i <= N; i++){

        A[i] = 1;
    }

    for(int i = 2; i * i <= N; i++){
        if(A[i] == 1){
            for(int j = i * i; j <= N; j+=i){
                A[j] = 0;
            }
        }
    }
    for(int i = 0; i < N; i++){

        if(A[i] == 1){
            printf("%d ",i);
        }
    }
    return 0;
}