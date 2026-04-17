#include <stdio.h>
#include <hamakou.h>

// 自然数n以下の素数を全て求める。
main(){

	int i, j, n, natural[100000];

	// 1. 自然数nの入力
	n = getint("Input n: ");

	// 2. 1を除くn以下の自然数を用意する
	for(i = 2; i <= n; i++){
		natural[i] = 1;
	}

	// 3. 倍数を次々に消去していく
	i = 2;
	while(i <= n){
		// 3-1. 自然数iの倍数をすべて消去する
		j = i * 2;
		while(j <= n){
			natural[j] = 0;
			j += i;
		}

		// 3-2. 次の自然数iを選ぶ
		// 既にiが倍数と認識されていればスキップ
		i++;
		while(natural[i] == 0 && i <= n){
			i++;
		}
	}

	// 4. 残った自然数（素数）を表示する
	printf("素数 : ");
	for(i = 2; i <= n; i++){
		if(natural[i] == 1){
			printf("%d ",i);
		}
	}
	printf("\n");
}