#include <stdio.h>
#include <hamakou.h>

// 自然数n以下の素数を全て求める。
main(){

	int i, j, n, natural[100000] = {};

	// 1. 自然数nの入力
	n = getint("Input n: ");

	// 2. 1,2,偶数を除くn以下の自然数を用意する
	for(i = 3; i <= n; i+=2){
		natural[i] = 1;
	}
	// 2を奇数として扱う
	natural[2] = 1;

	// 3. 倍数を次々に消去していく 2の場合を除いた3からスタート
	i = 3;

	// 倍数を見るので、i*i <= nの範囲内でよい
	while(i*i <= n){
		// 3-1. 自然数iの倍数をすべて消去する
		j = i * i;
		while(j <= n){
			natural[j] = 0;
			j += (i*2);
		}

		// 3-2. 次の自然数iを選ぶ
		// 既にiが倍数と認識されていればスキップ
		i+=2;
		// 同じくi^2 <= nの範囲内でよい
		while(natural[i] == 0 && i*i <= n){
			i+=2;
		}
	}

	// 4. 残った自然数（素数）を表示する
	#ifndef NO_DISP

	// 唯一の偶数の奇数2を単独で表示
	printf("素数 : 2 ");
	for(i = 3; i <= n; i+=2){
		if(natural[i] == 1){
			printf("%d ",i);
		}
	}
	printf("\n");

	#endif
}