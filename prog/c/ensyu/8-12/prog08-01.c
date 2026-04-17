#include <stdio.h>
#include <hamakou.h>


int sumConsInt(int n);
/*-----sumConstInt()-----
/ 1 ~ n(入力する整数:n) までの総和を返す
[引　数] 整数:n
[戻り値] 
	n >= 0 のとき: n以下の連続する整数の和
	n  < 0 のとき: -1 
-------------------------*/

main(){

	// 入力
	int n;
	n = getint("Input n: ");

	// 出力
	printf("Ans = %d\n", sumConsInt(n));

	return(0);
}

int sumConsInt(int n){

	if(n < 0){
		return (-1);
	}

	int i, sum = 0;
	for(i = 1; i <= n; i++){
		sum += i;
	}
	return (sum);
}

