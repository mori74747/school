#include <stdio.h>
#include <hamakou.h>

int sumConsInt(int n);
/*-----sumConstInt()-----
/ 1 ~ n(入力する整数:n) までの総和を返す
[引　数] 任意の整数:n
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

	int sum;
	sum = n*(n+1) / 2;

	return (sum);
}