#include <stdio.h>
#include <hamakou.h>

main(){

	int i, j, n, mpos;
	double min, a[1000];

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

	// n個の数値 a[0],a[1]...a[n-1]を小さい順に並べ替える
	i = 0;
	while(i < n-1){
		//i番目以降の最小値を見つける
		mpos = i;
		j = i + 1;
		while(j < n){
			/* minとa[i]を比較して必要ならminを更新する*/
			if(a[j] < a[mpos]){
				mpos = j;
			}
			// jの更新
			j = j + 1;
		}
		// 最小値をa[i]と入れ替える
		if(i != mpos){
			min = a[mpos];
			a[mpos] = a[i];
			a[i] = min;
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