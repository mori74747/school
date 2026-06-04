#include <stdio.h>

int main(){

    // 変数の入力
    long long x, n;
    scanf("%lld %lld", &x, &n);

    int c[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }

    // 尺取り法の初期化
    int left = 0;
    long long sum = 0;
    int ans = n+1;

    // 尺取り法手順
    for(int right = 0; right < n; right++){

        sum += c[right];

        // xがsum以上である（条件を満たしている間ループ)
        while(sum >= x){

            // 条件を満たしている間はできる限り縮めたい
            int len = right - left + 1;
            if(len < ans){
                ans = len;
            }
            sum -= c[left];
            left++;
        }
    }
    // ans が更新されていなければ-1を出力
    if(ans == n + 1){
        printf("-1\n");
    }else{
        printf("%d\n", ans);
    }

    return (0);
}