#include <stdio.h>
#include <hamakou.h>

main(){

	int i, j, n, mpos;
	double max, a[1000];

	// nの入力
	n = getfloat("Input n: ");

	// 配列の入力
	i = 0;
	while(i < n){
		printf("Input a[%d]: ",i);
		a[i] = getfloat("");

		// i の更新
		i = i + 1;
	}

	// n個の数値 a[0],a[1]...a[n-1]を大きい順に並べ替える
	i = 0;
	while(i < n-1){
		//i番目以降の最大値を見つける
		mpos = i;
		j = i + 1;
		while(j < n){
			/* maxとa[i]を比較して必要ならmaxを更新する*/
			if(a[j] > a[mpos]){
				mpos = j;
			}
			// jの更新
			j = j + 1;
		}
		// 最大値をa[i]と入れ替える
		if(i != mpos){
			max = a[mpos];
			a[mpos] = a[i];
			a[i] = max;
		}
		// iの更新
		i = i + 1;
	}
	
	// 配列の出力
	i = 0;
	while(i < n){
		printf("a[%d] = %g\n", i, a[i]);

		// iの更新
		i = i + 1;
	}

	return (0);
}