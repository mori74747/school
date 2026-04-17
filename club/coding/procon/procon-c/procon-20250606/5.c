//後書き
#include <stdio.h>

int main(){

    int M,K;
    scanf("%d%d",&M,&K);

    int H[366] = {0};
    int A,B;

    for(int i = 1; i <= M; i++){

        scanf("%d",&H[i]);
        //その日とその昨日の値をたす
        //⇒累積和
        H[i] += H[i-1];
    }
    for(int i = 0; i < K; i++){

        scanf("%d%d",&A,&B);
        int ans = (H[B] - H[A-1]) / (B-A+1);
        //ansに累積和を使ってB日目からA日目までの値を引いて
        //A日目からB日目までのスミン時間を出す。
        printf("%d\n",ans);
    }
    return 0;
}