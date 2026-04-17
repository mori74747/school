// 1996 - ビット王国探検隊のkamba君

#include <stdio.h>

int main(){

    int N, i;

    scanf("%d",&N);

    int x[N];
    float y[N];
    float ans;

    for(i = 0; i < N; i++){

        scanf("%d%f",&x[i],&y[i]);

        ans = x[i] + y[i];

        printf("%f\n",ans);
    }

    return 0;
}
