#include <stdio.h>
#include <hamakou.h>

// 自然数n以下の素数を求める
main(){
	// 1. 自然数nを入力する
	int i, j, n;
	n = getint("Input n: ");
	// 2. 素数2をそのまま表示する
	printf("素数： 2 ");

	// 3. n以下の奇数を素数かどうか順に調べ、素数なら表示する。
	for(i = 3; i <= n; i+=2){
		// 3.1 奇数iが素数かどうか調べる。
		j = 3;
		// 3.1.1 [jがiの平方根より小さい], 3.1.2 [iがjで割り切れない]
		while((j*j < i)&&(i % j != 0)){
			j = j + 2;
		}
		// 3.2 奇数iが素数ならiを表示する。
		if(j*j > i){
			// 3.3 奇数を表示する
			printf("%i ",i);
		}
	}
	// 改行の出力
	printf("\n");
}