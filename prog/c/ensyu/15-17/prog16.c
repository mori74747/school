#include <stdio.h>
#include <hamakou.h>

#define MAX_SIZE   100
#define MAX_NAME   21
#define MAX_POINT  100
// テストデータの格納用
#define SUB_SIZE   3

#define japanese   0
#define math       1
#define english    2

int inputData(int n, char name[][MAX_NAME], char famname[][MAX_NAME], int testData[][MAX_SIZE]);

main()
{
	char      name[MAX_SIZE][MAX_NAME]; // 名を格納する配列
	char   famname[MAX_SIZE][MAX_NAME]; // 姓を格納する配列
	int   testData[SUB_SIZE][MAX_SIZE]; // テストデータを記録する配列
	int    stu_sum[MAX_SIZE];           // 各生徒の合計点数を格納する配列
	int    sub_sum[SUB_SIZE];           // 各教科の合計点数を格納する配列
	double stu_avg[MAX_SIZE];           // 各生徒の平均点数を格納する配列
	double sub_avg[SUB_SIZE];           // 各教科の平均点数を格納する配列
	int       rank[MAX_SIZE];           // 順位を格納する配列

	int n;                            // 入力したいデータの個数
	
	// ｎ個のデータをそれぞれの配列へ入力
	// 出席番号を要素数として、任意の場所に格納する。
	inputData(n, name, famname, testData);

	// 

	return(0);
}

//--------------------------------------------------------------------------
//  入力データをそれぞれの配列に入力する。
//    第１引数 n           ：入力したいデータの個数
//    第２引数 name[]      ：名を格納する配列
//    第３引数 famname[]   ：姓を格納する配列
//    第４引数 testData[][]：テストデータを格納する配列
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
int inputData(int n, char name[][MAX_NAME], char famname[][MAX_NAME], int testData[][MAX_SIZE]){

	int i;
	for(i = 0; i < n; i++){

		int num = getint("出席番号:");
		scanf("名:%s",name[num]);
		scanf("姓:%s",famname[num]);
		// テストデータの入力
		scanf("国語:%d",testData[i][japanese]);
		scanf("数学:%d",testData[i][math]);
		scanf("英語:%d",testData[i][english]);
	}

	return;
}

//--------------------------------------------------------------------------
//   配列ｘに格納されているｎ個のデータの合計を求める
//    第１引数 n  ：配列に格納されているデータの個数          
//    第２引数 x[]：倍精度実数データが格納されている配列              
//    戻 り 値　　：配列ｘに格納されている倍精度実数データの合計
//--------------------------------------------------------------------------
int sumData(int n, int x[]){
	
}

//--------------------------------------------------------------------------
//   配列ｘに格納されているｎ個の実数データを表示する
//    第１引数 n  ：配列に格納されているデータの個数          
//    第２引数 x[]：倍精度実数データが格納されている配列              
//    戻 り 値　　：なし
//--------------------------------------------------------------------------
void showData(int n, double x[]){
	int i;
	for(i = 0; i < n; i++){
		printf("x[%3d]: %g\n",i,x[i]);
	}
	return;
}