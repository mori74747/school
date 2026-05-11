#include <stdio.h>
#include <string.h>
#include <hamakou.h>

#define MAX_SIZE   100
#define MAX_NAME   42
#define MAX_POINT  100
// テストデータの格納用
#define SUB_SIZE   3
// 各生徒、各教科のデータ管理用
#define STU 0
#define SUB 1

void inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]);
void sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]);
void avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]);
void calcRank(int n, int sum[][MAX_SIZE], int rank[]);
void showData(  int n,
				char   name[][MAX_NAME],
				int    testData[][SUB_SIZE],
				int    sum[][MAX_SIZE],
				double avg[][MAX_SIZE],
				int    rank[]
			);
void showFreq(int n, int sum[][MAX_SIZE]);

main()
{
	char      name[MAX_SIZE][MAX_NAME]; // 名前を格納する配列
	int   testData[MAX_SIZE][SUB_SIZE]; // 試験データを記録する配列
	int        sum[2][MAX_SIZE];        // 合計点数を格納する配列
	double     avg[2][MAX_SIZE];        // 平均点数を格納する配列
	int       rank[MAX_SIZE];           // 順位を格納する配列

	int n;                              // 入力したいデータの個数
	n = getint("人数:");

	inputData(n, name, testData);

	calcSum(n, testData, sum);

	calcAverage(n, sum, avg);

	calcRank(n, sum, rank);

	showData( n,
				name,
				testData,
				sum,
				avg,
				rank );

	showFreq(n, sum);

	// 

	return(0);
}

//--------------------------------------------------------------------------
//  入力データをそれぞれの配列に入力する。
//    第１引数 n           ：入力したいデータの個数
//    第２引数 name[]      ：名前を格納する配列
//    第４引数 testData[][]：試験データを格納する配列
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]){

	int i;
	for(i = 0; i < n; i++){

		int num = getint("出席番号:");
		num--;

		char familyName[21];
		char mainName[21];

		printf("姓:");
		scanf("%20s", familyName);

		printf("名:");
		scanf("%20s", mainName);

		// 姓をコピー
		strcpy(name[num], familyName);
		// 空白追加
		strcat(name[num], " ");
		// 名追加
		strcat(name[num], mainName);

		// テストデータの入力
		int j;
		for(j = 0; j < SUB_SIZE; j++){
			scanf("%d",testData[num][j]);
		}
	}

	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの合計を求める
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 testData[][]：データが格納されている配列 
//    第３引数 sum[]       ：合計データを格納する配列             
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]){
	int i, j;

	// 生徒ごと合計
	for(i = 0; i < n; i++){

		sum[STU][i] = 0;

		for(j = 0; j < SUB_SIZE; j++){
			sum[STU][i] += testData[i][j];
		}
	}

	// 教科ごと合計
	for(j = 0; j < SUB_SIZE; j++){

		sum[SUB][j] = 0;

		for(i = 0; i < n; i++){
			sum[SUB][j] += testData[i][j];
		}
	}
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの平均を求める
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 testData[][]：データが格納されている配列 
//    第３引数 avg[]       ：合計データを格納する配列             
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]){
	int i;

	// 生徒平均
	for(i = 0; i < n; i++){

		avg[STU][i] = (double)(sum[STU][i] / SUB_SIZE);
	}

	// 教科平均
	for(i = 0; i < SUB_SIZE; i++){

		avg[SUB][i] = (double)(sum[SUB][i] / n);
	}
}

void calcRank(int n, int sum[][MAX_SIZE], int rank[]){
	int i, j;

	for(i = 0; i < n; i++){

		rank[i] = 1;

		for(j = 0; j < n; j++){

			if(sum[STU][j] > sum[STU][i]){
				rank[i]++;
			}
		}
	}
}

//--------------------------------------------------------------------------
//   配列ｘに格納されているｎ個の実数データを表示する
//    第１引数 n  ：配列に格納されているデータの個数          
//    第２引数 x[]：倍精度実数データが格納されている配列              
//    戻 り 値　　：なし
//--------------------------------------------------------------------------
void showData(  int n,
				char   name[][MAX_NAME],
				int    testData[][SUB_SIZE],
				int    sum[][MAX_SIZE],
				double avg[][MAX_SIZE],
				int    rank[]
			){
	int i;

	printf("\n");
	printf("試験成績一覧表\n\n");

	printf("NO  氏名                     ");
	printf("国語  英語  数学  合計  順位  平均\n");

	for(i = 0; i < n; i++){

		printf("%2d  ", i + 1);
		printf("%-25s", name[i]);

		int j;
		for(j = 0; j < SUB_SIZE; j++){
			printf("%6d", testData[i][j]);
		}

		printf("%6d", sum[STU][i]);
		printf("%6d", rank[i]);
		printf("%7.2f", avg[STU][i]);

		printf("\n");
	}

	printf("\n");
    printf("合計");
	int i;
	int all_sum = 0;
	for(i = 0; i < SUB_SIZE; i++){
		printf("%6d", sum[SUB][i]);
		all_sum += sum[SUB][i];
	}
	printf("%6d\n", all_sum);

	printf("平均");
	int i;
	double all_avg = 0;
	for(i = 0; i < SUB_SIZE; i++){
		printf("%6.2g", avg[SUB][i]);
		all_avg += avg[SUB][i];
	}
	printf("%6.2g\n", all_avg);
}

void showFreq(int n, int sum[][MAX_SIZE]){
	int freq[7] = {0};

	int i, j;
	for(i = 0; i < n; i++){

		int s = sum[STU][i];

		if(s < 50){
			freq[0]++;
		}
		else if(s < 100){
			freq[1]++;
		}
		else if(s < 150){
			freq[2]++;
		}
		else if(s < 200){
			freq[3]++;
		}
		else if(s < 250){
			freq[4]++;
		}
		else if(s < 300){
			freq[5]++;
		}
		else{
			freq[6]++;
		}
	}

	printf("\n");
	printf("度数分布\n\n");

	for(i = 0; i < 7; i++){

		int min = i * 50;
		int max = min + 49;

		if(i == 6){
			printf("300 -     ");
		}
		else{
			printf("%3d - %3d ", min, max);
		}
		printf("[%d] ", freq[i]);

		for(j = 0; j < freq[i]; j++){
			printf("*");
		}

		printf("\n");
	}
}