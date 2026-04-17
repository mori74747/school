#include <stdio.h>
#include <hamakou.h>

main(){

	// 入力
	int m, n, i, j, pos;
	char T[1000001],  C[1000001];
	m = getstring("Input T: ",T);
	n = getstring("Input C: ",C);

	// 場所の初期化
	pos = -1;

	// 処理部分
	if(n == 0){
		// 文字列の長さ(n) が 0の時の処理
		// Cの入力がない（Cは空文字）なら、Tのどこにでも存在し得ると考える
		pos = 0;
	}else{
		// 文字列の検索
		i = 0;
		while((i <= m-n) && (pos == -1)){
			// 前から順に比較する。文字列の最後まで同じである限りループ
			j = 0;
			while((j < n) && (T[i+j] == C[j])){
				j++;
			}
			// 比較のチェック
			if(j == n){
				pos = i;
			}
			i++;
		}
	}

	printf("検索結果: %d\n",pos);

	return (0);
}