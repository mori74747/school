#include <stdio.h>

int main(){

    int ans=0, N;
    scanf("%d",&N);

    int A[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&A[i]);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-1-i; j++){

            if(A[j] < A[j+1]){

                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
    
    int Q;
    scanf("%d",&Q);

    int X[Q];
    for(int i = 0; i < Q; i++){
        scanf("%d",&X[i]);

        for(int j = 0; j < N; j++){

            if(A[j] == X[i]){
                printf("Yes\n");
                ans++;
            }
        }
        if(ans == 0){
            printf("No\n");
        }else{
            ans = 0;
        }
    }

    return 0;
}