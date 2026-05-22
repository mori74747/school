#include <stdio.h>
#include <hamakou.h>
main()
{

	int n;           // n個の整数
	int data[100];   // 整数を保存する配列

	// nの入力
	n = getint("データの個数: ");
	// データの入力
	int i;
	for(i = 0; i < n; i++){
		printf("%d個目のデータ: ", i+1);
		scanf("%d",&data[i]);
	}
	
	// データの出力
	for(i = 0; i < n; i++){
		printf("%d個目のデータ: %d\n", i+1, data[i]);
	}

	return (0);
}