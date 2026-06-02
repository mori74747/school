#include <stdio.h>

int main(){

	int x, n;
	scanf("%d%d", &x, &n);

	int c[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}

	int left = 0;
	long long sum = 0;
	int ans = 0;

	for(int right = 0; right < n; right++){

		sum += c[right];

		while(sum > x){
			sum -= c[left];
			left++;
		}

		int len = right - left + 1;
		if(ans < len){
			ans = len;
		}
	}

	printf("%d\n", ans);

	return 0;
}