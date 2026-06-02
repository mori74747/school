#include <stdio.h>

int main(){

	// 変数の入力
	int x, n;
	scanf("%d %d", &x, &n);

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

		while(sum >= x){

			// 最大長から最短長になると、更新タイミングが変わる
			// 更新した後に広げる動作を行う
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