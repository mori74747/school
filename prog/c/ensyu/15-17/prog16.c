#include <stdio.h>
#include <string.h>
#include <hamakou.h>

#define MAX_SIZE   100
#define MAX_NAME   42
#define MAX_POINT  100
#define FREQ_SIZE  7
#define BUFF_SIZE  256
// テストデータの格納用
#define SUB_SIZE   3
// 各生徒、各教科のデータ管理用
#define STU 0
#define SUB 1
#define ALL 2

int  inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]);
void sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]);
void avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]);
void calcRank(int n, int sum[][MAX_SIZE], int rank[]);
void makeFreq(int n, int sum[][MAX_SIZE], int freq[]);
void showData(  int n,
				char   name[][MAX_NAME],
				int    testData[][SUB_SIZE],
				int    sum[][MAX_SIZE],
				double avg[][MAX_SIZE],
				int    rank[]
			);
void showFreq(int n, int freq[FREQ_SIZE]);

main()
{
	char      name[MAX_SIZE][MAX_NAME]; // 名前を格納する配列
	int   testData[MAX_SIZE][SUB_SIZE]; // 試験データを記録する配列
	int        sum[2][MAX_SIZE] = {};   // 合計点数を格納する配列
	double     avg[2][MAX_SIZE];        // 平均点数を格納する配列
	int       rank[MAX_SIZE];           // 順位を格納する配列
	int       freq[FREQ_SIZE] = {};     // 度数分布を格納する配列
	int        num;                     // 実際に入力できたデータの個数
	int          n;                     // 入力したいデータの個数

	n = getint("入力データの数：");
	// ｎ個のデータをそれぞれの配列へ入力
	// 入力できないデータがあった時は警告
	if ((num = inputData(n, name, testData)) < n) {
		printf("\n入力データ数が配列の上限を超えました。\n");
		printf("入力できたデータのみについて集計します。\n");
	}

	// データの入力

	// データの合計を計算(各生徒・各教科)
	sumData(num, testData, sum);

	// データの平均を計算(各生徒・各教科)
	avgData(num, sum, avg);

	// データの順位を計算
	calcRank(num, sum, rank);

	// 度数分布表の作成
	makeFreq(num, sum, freq);
	// データの表示
	showData(   num,
				name,
				testData,
				sum,
				avg,
				rank );

	// 度数分布表の表示
	showFreq(num, freq);

	return(0);
}

//--------------------------------------------------------------------------
//  入力データをそれぞれの配列に入力する。
//  name[] に 与えられた姓と名を空白区切りで入力
//  testData[][] に 各生徒ごとの各教科の点数を入力
//
//    第１引数 n           ：入力したいデータの個数
//    第２引数 name[]      ：名前を格納する配列
//    第３引数 testData[][]：試験データを格納する配列
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
int inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]){

	int i, size = n;
	// 入力個数の規制
	if(size > MAX_SIZE){
		size = MAX_SIZE;
	}

	printf("NO , 姓 , 名 , テストの点数 を 空白区切りで入力\n");
	for(i = 0; i < n; i++){

		int pos = 0, ct;
		char buff[BUFF_SIZE] = {};
		fgets(buff, sizeof(buff), stdin);

		int No;
		sscanf(buff, "%d%n", &No, &ct);
		pos += ct;
		No--;

		char familyName[21];
		char mainName[21];

		sscanf(buff + pos, "%s %s%n", familyName, mainName, &ct);
		pos += ct;

		// 姓をコピー
		strcpy(name[No], familyName);
		// 空白追加
		
		strcat(name[No], " ");
		// 名追加
		strcat(name[No], mainName);

		// テストデータの入力
		int j;
		for(j = 0; j < SUB_SIZE; j++){
			sscanf(buff + pos, "%d%n", &testData[No][j], &ct);
			pos += ct;
		}
	}

	return(size);
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの合計を求める
//   生徒ごとの合計と教科ごとの合計をsumの[STU]と[SUB]に分けて入力
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 testData[][]：データが格納されている配列 
//    第３引数 sum[][]     ：合計データを格納する配列             
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]){
	int i, j;

	// 合計の計算
	for(i = 0; i < n; i++){
		for(j = 0; j < SUB_SIZE; j++){

			sum[STU][i] += testData[i][j];
			sum[SUB][j] += testData[i][j];
			sum[ALL][0] += testData[i][j];
		}
	}
	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの平均を求める
//   生徒ごとの平均と教科ごとの平均をavgの[STU]と[SUB]に分けて入力
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 sum[][]     ：合計データが格納されている配列 
//    第３引数 avg[][]     ：平均データを格納する配列             
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]){
	int i;

	// 生徒平均
	for(i = 0; i < n; i++){

		avg[STU][i] = (double)sum[STU][i] / SUB_SIZE;
	}

	// 教科平均
	for(i = 0; i < SUB_SIZE; i++){

		avg[SUB][i] = (double)sum[SUB][i] / n;
	}
	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの順位を求める
//   生徒の合計データから生徒の順位をrank[]に入力
//
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 sum[][]     ：合計データが格納されている配列 
//    第３引数 rank[]      ：順位データを格納する配列             
//    戻 り 値             ：なし
//--------------------------------------------------------------------------

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
	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータを表示する
//    第１引数 n           ：配列に格納されているデータの個数
//    第２引数 name[][]    ：名前が格納されている配列
//    第３引数 testData[][]：試験データが格納されている配列
//    第４引数 sum[][]     ：合計データが格納されている配列
//    第５引数 avg[][]     ：平均データが格納されている配列
//    第６引数 rank[]      ：順位データが格納されている配列
//    戻 り 値　　         ：なし
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

	printf("%-3s %-32s %7s %9s %9s %9s %9s %10s\n",
		"NO  ",
		"氏名",
		"国語",
		"数学",
		"英語",
		"合計",
		"順位",
		"平均\n");

	for(i = 0; i < n; i++){

		printf("%3d  ", i + 1);
		printf("%-28s", name[i]);

		int j;
		for(j = 0; j < SUB_SIZE; j++){
			printf("%8d", testData[i][j]);
		}

		printf("%8d", sum[STU][i]);
		printf("%8d", rank[i]);
		printf("%8.2f", avg[STU][i]);

		printf("\n");
	}

	printf("\n");
    printf("%35s","合計  ");
	
	printf("%8d\n", sum[ALL][0]);

	printf("%35s","平均  ");
	for(i = 0; i < SUB_SIZE; i++){
		printf("%8.2f", avg[SUB][i]);
	}
	double all_avg = (double)sum[ALL][0] / n;
	printf("%8.2f\n", all_avg);

	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの度数分布表を作成する
//   各生徒の合計データから度数分布表を作成
//
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 sum[][]     ：合計データが格納されている配列
//    戻 り 値             ：なし
//--------------------------------------------------------------------------

void makeFreq(int n, int sum[][MAX_SIZE], int freq[]){

	int i, j;
	for(i = 0; i < n; i++){

		int s = sum[STU][i];

		freq[s/50]++;
	}
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの度数分布表からヒストグラムを表示
//
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 freq[]      ：合計データが格納されている配列
//    戻 り 値             ：なし
//--------------------------------------------------------------------------

void showFreq(int n, int freq[]){
	
	printf("\n\n");
	int i, j;
	for(i = 0; i < 7; i++){

		int min = i * 50;
		int max = min + 49;

		if(i == 6){
			printf("%-10s","300");
		}
		else{
			printf("%3d - %3d ", min, max);
		}
		printf("[%2d] ", freq[i]);

		for(j = 0; j < freq[i]; j++){
			printf("*");
		}

		printf("\n");
	}
	return;
}