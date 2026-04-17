//011 - sortJadge
//後付け
#include <stdio.h>

int main(){

    int N, i, x=0, y=0;

    scanf("%d",&N);

    int A[N];

    for(i = 0; i < N; i++){

        scanf("%d",&A[i]);

        if(i > 0){

            if(A[i-1] <= A[i]){

                x++;
            }
            else if(A[i-1] >= A[i]){

                y++;
            }
        }
    }
    if(x == N-1){

        printf("1\n");
    }
    else if(y == N-1){

        printf("2\n");
    }
    else{

        printf("0\n");
    }

    return 0;
}