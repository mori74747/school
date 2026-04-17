//後書き(自分自身)
#include <stdio.h>

int main(){

    int N,X;
    scanf("%d%d",&N,&X);

    int V[N];
    int total = 0, temp = 0;

    for(int i = 0; i < N; i++){

        scanf("%d",&V[i]);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-1-i; j++){

            if(V[j] > V[j+1]){

                int tmp = V[j];
                V[j] = V[j+1];
                V[j+1] = tmp;
            }
        }
    }
    for(int i = 0; temp == 0; i++){

        total += V[i];
        if(total > X){
            printf("%d\n",i-1);
            temp++;
        }
    }
    return 0;
}