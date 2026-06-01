#include <stdio.h>

int main(){

	int x, n;
	scanf("%d%d",&x,&n);

	int c[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&c[i]);
	}
	int left  = 0;
	int right = 0;

	int sum = c[0];
	int max = 0;

	while(right < n){
		if(sum <= x){
			if(max < (right - left + 1)){
				max = right - left + 1;
			}
			if(right + 1 < n){
				right++;
				sum += c[right];
			}else{
				break;
			}
		}else{
			sum -= c[left];
			left++;
		}
	}
	printf("%d\n",max);

	return (0);
}