#include <stdio.h>
#include <hamakou.h>

int chkFizzBuzz(int x, int m, int n);
/*-----chkFizzBuzz()-----
与えられた整数x, m, n　より、以下の値を返す
[引　数] 
	任意の整数: x, m, n
[戻り値] 
	x が 0 のとき 0
	x が mのみの倍数 のとき 1
	x が nのみの倍数 のとき 2
	x が mとnの両方の倍数(公倍数) のとき 3
	x が mとnのどちらの倍数でない とき -1
------------------------*/

main(){

	// 入力
	int z, m, n;
	z = getint("Input z: ");
	m = getint("Input m: ");
	n = getint("Input n: ");

	// -z ~ zのループ処理・出力
	int i;
	for(i = z * -1; i <= z; i++){
		printf("%d ",i);
		int check = chkFizzBuzz(i, m, n);

		if(check == 3){
			printf("FizzBuzz\n");
		}
		else if(check == 1){
			printf("Fizz\n");
		}
		else if(check == 2){
			printf("Buzz\n");
		}else{
			printf("\n");
		}
	}
	
	return(0);
}

int chkFizzBuzz(int x, int m, int n){

	if(x == 0){
		return (0);
	}
	if(x % m == 0 && x % n == 0){
		return (3);
	}
	if(x % m == 0){
		return (1);
	}
	if(x % n == 0){
		return (2);
	}
	return (-1);
}