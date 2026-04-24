#include<stdio.h>
#include<hamako.h>

#define SIZE 5
int array_max(int n, int num[]);

main()
{
	int max;
	int num[SIZE] = {11,23,15,46,32};

	// 関数を使って配列の中から最大値を求める
	max = array_max(SIZE, num);

	printf("最大値は %d \n",max);

	return(0);
}

//--------------------------------------------------------
// 配列numに格納されているn個のデータから、最大値を求める
// 　第１引数 n　　：入力したいデータの個数
// 　第２引数 num[]：整数データが格納されている配列
// 　戻り値　　　　：配列の中の最大値
//--------------------------------------------------------
int array_max(int n, int num[])
{
	int i, max;
	max = num[0];
	
	for( i = 1 ; i < n ; i++ ){
		if(max < num[i]){
			max = num[i];
		}
	}

	return(max);
}
