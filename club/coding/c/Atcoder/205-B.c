//B - Permutation Check

#include <stdio.h>

int main(){

    int N,i,m,a=0;

    scanf("%d",&N);

    int A[N];
    int B[N];

    for(i = 0; i < N; i++){

        scanf("%d",&A[i]);
    }

    for(m = 0; m < N; m++){

        for(i = 0; A[i] != m+1 && i <= N; i++){

        }if(A[i] == m+1){

        }else{

            a--;
        }

    }
    if(a == 0){

        printf("Yes\n");
    }else{

        printf("No\n");
    }

    return 0;
}