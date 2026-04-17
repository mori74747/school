//後書き
#include <stdio.h>

int main(){

    int N, ans=0;
    scanf("%d",&N);
    int A[N+1];

    for(int i = 2; i <= N; i++){

        A[i] = 1;
    }
    A[0] = 0;
    A[1] = 0;
    
    for(int i = 2; i * i <= N; i++){
        if(A[i] == 1){
            for(int j = i * i; j <= N; j+=i){
                A[j] = 0;
            }
        }
    }
    for(int i = 1; i <= N; i++){

        if(A[i] == 0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}