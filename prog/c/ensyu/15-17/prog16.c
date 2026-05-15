#include <stdio.h>
#include <string.h>
#include <hamakou.h>

#define MAX_SIZE   1
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

int   inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]);
void    sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]);
void    avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]);
void   calcRank(int n, int sum[][MAX_SIZE], int rank[]);
void   makeFreq(int n, int sum[][MAX_SIZE], int freq[]);
void   showData(int n,
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
	int        sum[3][MAX_SIZE] = {};   // 合計点数を格納する配列
	double     avg[3][MAX_SIZE];        // 平均点数を格納する配列
	int       rank[MAX_SIZE];           // 順位を格納する配列
	int       freq[FREQ_SIZE] = {};     // 度数分布を格納する配列
	int        num;                     // 実際に入力できたデータの個数
	int          n;                     // 入力したいデータの個数

	n = getint("人数：");
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
//                          name[i]のときi+1番が出席番号の人の名前が格納されている配列
//    第３引数 testData[][]：試験データを格納する配列
//                          testData[][0~2]に「国語」「数学」「英語」の順で格納
//                          testData[i][]  に i+1番が出席番号の人のデータを格納
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
int inputData(int n, char name[][MAX_NAME], int testData[][SUB_SIZE]){

	int i, size = n;
	// 入力個数の規制
	if(size > MAX_SIZE){
		size = MAX_SIZE;
	}

	// 入力
	printf("NO , 姓 , 名 , テストの点数 を 空白区切りで入力\n");
	for(i = 0; i < n; i++){

		int pos = 0, ct;
		char buff[BUFF_SIZE] = {};
		fgets(buff, sizeof(buff), stdin);

		// A.番号を入力
		int No;
		sscanf(buff, "%d%n", &No, &ct);
		pos += ct;
		No--;

		char familyName[21];
		char mainName[21];

		// B.名前の入力
		sscanf(buff + pos, "%s %s%n", familyName, mainName, &ct);
		pos += ct;

		// B.1姓をコピー
		strcpy(name[No], familyName);
		
		// B.2空白追加
		strcat(name[No], " ");

		// B.3名追加
		strcat(name[No], mainName);

		// C.テストデータの入力
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
//   生徒ごとの合計と教科ごとの合計をsumの[STU]と[SUB]に分けて求めて格納
//   全体の合計を[ALL]に格納
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 testData[][]：データが格納されている配列
//                          testData[][0~SUB_SIZE-1]に「国語」「数学」「英語」の順で格納されている配列
//                          testData[i][]のときに       i+1番が出席番号の人のデータを格納されている配列
//    第３引数 sum[][]     ：合計データを格納する配列 
//                          sum[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の合計点数を格納する

//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void sumData(int n, int testData[][SUB_SIZE], int sum[][MAX_SIZE]){
	int i, j;

	// A.合計の計算
	for(i = 0; i < n; i++){
		for(j = 0; j < SUB_SIZE; j++){

			// A.1 生徒ごとの合計点数
			sum[STU][i] += testData[i][j];
			// A.2 教科ごとの合計点数
			sum[SUB][j] += testData[i][j];
			// A.3 全部の合計点数
			sum[ALL][0] += testData[i][j];
		}
	}
	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの平均を求める
//   生徒ごとの平均と教科ごとの平均をavgの[STU]と[SUB]に分けて格納
//   全体の平均を[ALL]に格納
//    第１引数 n           ：配列に格納されているデータの個数          
//    第３引数 sum[][]     ：合計データを格納する配列 
//                          sum[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の合計点数が格納されている
//    第３引数 avg[][]     ：平均データを格納する配列             
//                          avg[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の平均点数が格納されている
//    戻 り 値             ：なし
//--------------------------------------------------------------------------
void avgData(int n, int sum[][MAX_SIZE], double avg[][MAX_SIZE]){
	int i;

	// A.生徒平均
	for(i = 0; i < n; i++){

		// A.1 i+1番の平均点数の計算
		avg[STU][i] = (double)sum[STU][i] / SUB_SIZE;
	}

	// B.教科平均
	for(i = 0; i < SUB_SIZE; i++){

		// B.1 i+1番目の教科の平均点数の計算
		avg[SUB][i] = (double)sum[SUB][i] / n;
	}

	// C.合計平均
	//   全体合計から生徒数を割った平均
	avg[ALL][0] = (double)sum[ALL][0] / n;

	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの順位を求める
//   生徒の合計データから生徒の順位をrank[]に入力
//
//    第１引数 n           ：配列に格納されているデータの個数          
//    第３引数 sum[][]     ：合計データを格納する配列 
//                          sum[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の合計点数が格納されている
//    第３引数 rank[]      ：順位データを格納する配列
//                        　rank[i]のときにi+1番が出席番号の人の順位を格納する
//    戻 り 値             ：なし
//--------------------------------------------------------------------------

void calcRank(int n, int sum[][MAX_SIZE], int rank[]){
	int i, j;

	// A 順位計算
	for(i = 0; i < n; i++){

		// A.1 i+1番目の人の順にを１位初期化する
		rank[i] = 1;

		// A.2 i+1番目の人より大きい人が何人いるか加算する
		for(j = 0; j < n; j++){

			// A.2-1 自身より大きい人がいるか確認
			if(sum[STU][j] > sum[STU][i]){
				// 順位を1つ加算する（順位を１つ下げる）
				rank[i]++;
			}
		}
	}
	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータを表示する
//    第１引数 n           ：配列に格納されているデータの個数
//    第２引数 name[]      ：名前を格納する配列
//                          name[i]のときi+1番が出席番号の人の名前が格納されている配列
//    第３引数 testData[][]：データが格納されている配列
//                          testData[][0~SUB_SIZE-1]に「国語」「数学」「英語」の順で格納されている配列
//                          testData[i][]のときに       i+1番が出席番号の人のデータを格納されている配列
//    第４引数 sum[][]     ：合計データを格納する配列 
//                          sum[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の合計点数が格納されている
//    第５引数 avg[][]     ：平均データを格納する配列             
//                          avg[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の平均点数が格納されている
//    第６引数 rank[]      ：順位データを格納する配列
//                        　rank[i]のときにi+1番が出席番号の人の順位を格納する
//    戻 り 値　　         ：なし
//--------------------------------------------------------------------------
void showData(  int n,
				char   name    [][MAX_NAME],
				int    testData[][SUB_SIZE],
				int    sum     [][MAX_SIZE],
				double avg     [][MAX_SIZE],
				int    rank    []
){
	int i;

	// A. 見出しの表示
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

	// B. 生徒のデータを表示
	for(i = 0; i < n; i++){

		// B.1 出席番号の表示
		printf("%3d  ", i + 1);

		// B.2 名前の表示
		printf("%-28s", name[i]);

		// B.3 各教科のテストデータの表示
		int j;
		for(j = 0; j < SUB_SIZE; j++){
			printf("%8d", testData[i][j]);
		}

		// B.4 生徒の合計点数の表示
		printf("%8d", sum[STU][i]);

		// B.5 生徒順位の表示
		printf("%8d", rank[i]);

		// B.6 生徒の平均点数の表示
		printf("%8.2f", avg[STU][i]);

		printf("\n");
	}

	printf("\n");

	// C 統計の表示
	// C.1 各教科合計の表示
    printf("%35s","合計  ");
	for(i = 0; i < SUB_SIZE; i++){
		printf("%8d", sum[SUB][i]);
	}
	// C.2 すべての合計点数の表示
	printf("%8d\n", sum[ALL][0]);

	// C.3 各教科平均の表示
	printf("%35s","平均  ");
	for(i = 0; i < SUB_SIZE; i++){
		printf("%8.2f", avg[SUB][i]);
	}
	
	// C.4 全生徒の平均の表示
	printf("%8.2f\n", avg[ALL][0]);

	return;
}

//--------------------------------------------------------------------------
//   配列に格納されているデータの度数分布表を作成する
//   各生徒の合計データから度数分布表を作成
//
//    第１引数 n           ：配列に格納されているデータの個数          
//    第２引数 sum[][]     ：合計データを格納する配列 
//                          sum[0~SUB_SIZE-1]で教科ごと(「国語」「数学」「英語」)の合計点数が格納されている
//    戻 り 値             ：なし
//--------------------------------------------------------------------------

void makeFreq(int n, int sum[][MAX_SIZE], int freq[]){

	// A. 度数分布表の計算
	int i, j;
	for(i = 0; i < n; i++){

		int s = sum[STU][i];

		// A.1 50ごとの度数分布のランク分け
		freq[s/50]++;
	}
	return;
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