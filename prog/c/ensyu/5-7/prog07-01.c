#include <stdio.h>
#include <hamakou.h>

main(){

	int N, M;
	// 1. 自然数n, mの入力
	N = getint("Input N: ");
	M = getint("Input M: ");

	// M が 0の時にエラー処理
	if(M == 0){
		printf("エラー\n");
	}else{
		// 2. 分数を既約な分数に直して表示する

		// 整数のかたまりを調べる
		int k = N/M;
		printf("%d/%d = ",N, M);

		// 整数になる場合とならない場合に場合分け
		if(N % M == 0){
			printf("%d\n",k);
		}else{
			// 既約分数にする。
			// 1より小さい分数になおす(M>Nの関係を作る)
			N = N - (k * M);
			// mとnの最大公約数を求める。(ユークリッドの互除法)
			// 互除法用の変数の用意
			int m = M, n = N;
			int r = m % n;
			while(r != 0){
				m = n;
				n = r;
				r = m % n;
			}
			// 分母と分子を最大公約数で割る
			N /= n;
			M /= n;
			// 既約分数と既約な帯分数に場合分け
			if(k == 0){
				printf("%d/%d\n",N,M);
			}else{
				printf("%d(%d/%d)\n",k,N,M);
			}
		}
	}

	return (0);
}