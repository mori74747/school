//後書き
#include <stdio.h>

int main(){

    int N, i, j;
    scanf("%d\n",&N);

    char C[N];
    int Time[7][N];
    int ans[12] = {};

    for(i = 0; i < N; i++){

        scanf("%c\n",&C[i]);
    }
    for(i = 0; i < 7; i++){
        for(j = 0; j < N; j++){

            scanf("%d",&Time[i][j]);

            ans[j] += Time[i][j];
        }
    }
    for(i = 0; i < N; i++){

        int answer = ans[i] / 7;
        printf("%c ",C[i]);
        printf("%d\n",answer);
    }
    return 0;
}