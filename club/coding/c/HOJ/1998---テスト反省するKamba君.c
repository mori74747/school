// 1998 - テスト反省するKamba君

#include <stdio.h>

int main(){

    int M, N, i, j, ans;

    scanf("%d %d\n",&M,&N);

    char C[N];
    int Data[M][N];

    int total[100] = {};

    for(i = 0; i < N; i++){

        scanf("%c\n",&C[i]);
    }
    for(i = 0; i < M; i++){

        for(j = 0; j < N; j++){

            scanf("%d",&Data[i][j]);
            
            total[j] += Data[i][j];
        }
    }
    for(j = 0; j < N; j++){

        ans = total[j] / M;

        printf("%c ",C[j]);
        printf("%d\n",ans);
    }
    


    return 0;
}