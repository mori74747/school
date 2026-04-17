#include <stdio.h>

int main(){

    int M, N, i, s;
    scanf("%d",&N);

    int Data[N], T;
    int left,right;

    for(i = 0; i < N; i++){

        scanf("%d",&Data[i]);
    }
    scanf("%d",&M);

    for(i = 0; i < M; i++){

        scanf("%d",&T);

        left = 0, right = N;

        while(left < right){

            s = (left + right) / 2;
            if(Data[s] > T){
                right = s;
            }
            else {
                left = s + 1;
            }
        }
        printf("%d\n",left);
    }


    return 0;
}