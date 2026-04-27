#include <stdio.h>
#include <string.h>

#define LINE_SIZE 51 // マップを格納する2次元配列のヌル文字を含む行サイズ

int readMap(char map[][LINE_SIZE]);
int showMap(int n, char map[][LINE_SIZE]);
int transformMap(int method, int n, char map1[][LINE_SIZE], char map2[][LINE_SIZE]);

main()
{
	char map1[LINE_SIZE - 1][LINE_SIZE]; // 元のマップを格納する２次元配列
	char map2[LINE_SIZE - 1][LINE_SIZE]; // 変換後のマップを格納する２次元配列
	int n;                                     // 入力したマップのサイズ

	n = readMap(map1);

	if(n < 0){
		printf("マップサイズが上限を超えています。\n");
	}else{
		printf("\n元の図形\n");
		showMap(n, map1);

		printf("\n90゜右回転\n");
		transformMap(1, n, map1, map2);
		showMap(n, map2);

		printf("\n90゜左回転\n");
		transformMap(2, n, map1, map2);
		showMap(n, map2);

		printf("\n左右反転\n");
		transformMap(3, n, map1, map2);
		showMap(n, map2);

		printf("\n上下反転\n");
		transformMap(4, n, map1, map2);
		showMap(n, map2);
		putchar('\n');  // 見やすくするための改行
	}

	return(0);
}

//---------------------------------------------------------------------------------
// 引　数 map[][LINE_SIZE] ： マップを読み込む２次元配列
// 戻り値                  ： 読み込んだマップのサイズ
//                            但し、LINE_SIZE 以上のときは -1 を返す
//
// n 行 n 列のマップを引数で指定した２次元配列に読み込み、読み込んだマップの
// サイズnを返す。なお、nとマップデータはこの順に標準入力より与えられる。
//  
// 但し、n の最大値は LINE_SIZE - 1 とし、これを超えるサイズのマップデータは
// 一切配列に読み込まず、-1 を返す。また、読み込んだマップデータ各行はヌル文字で
// 終端され、改行文字は含まない。
//---------------------------------------------------------------------------------
int readMap(char map[][LINE_SIZE]){
	int i, n;
	char buff[LINE_SIZE + 1]; // 入力用バッファ(改行とヌル文字を含めたサイズが必要)

	// n 行 n 列を表す n を入力
	fgets(buff, sizeof(buff), stdin);
	sscanf(buff, "%d", &n);

	if (n >= LINE_SIZE) { // 配列の行サイズを超えるマップは読み込まない
		return(-1);
	}else{
		for (i = 0; i < n; i++) {
      		// マップデータの１行分を入力（このとき改行も含まれるので注意）
			fgets(buff, sizeof(buff), stdin);
			buff[strcspn(buff, "\n")] = '\0';  // 行末の改行をヌル文字で上書き
			strcpy(map[i],buff);         // 入力行をマップ配列に格納
		}
		return(n);   // マップのサイズを返す
	}
}

//---------------------------------------------------------------------------------
// 第１引数 n                ： 表示するマップのサイズ
// 第２引数 map[][LINE_SIZE] ： マップが格納されている２次元配列
// 戻り値                    ： n ＜ LINE_SIZE のとき 1
//                              n ≧ LINE_SIZE のとき 0
// 引数で指定したサイズ n のマップを表示する
//---------------------------------------------------------------------------------
int showMap(int n, char map[][LINE_SIZE]){
	int i, j;

	if (n >= LINE_SIZE) {
		return (0);
	}else{
		for (i = 0; i < n; i++){
			printf("%s\n",map[i]);
		}
		return (1);
	}
}

//---------------------------------------------------------------------------------
// 第１引数 method            ： 変換方法
//                               1:90゜右回転, 2:90゜左回転, 3:左右反転, 4:上下反転
// 第２引数 n                 ： 表示するマップのサイズ
// 第３引数 map1[][LINE_SIZE] ： 変換元のマップが格納された２次元配列
// 第４引数 map2[][LINE_SIZE] ： 変換後のマップを格納する２次元配列
// 戻り値                     ： n ＜ line_size のとき 1
//                               n ≧ line_size のとき 0
//
// サイズｎのマップ map1[][] を第２引数で指定した方法で変換し、map2[][] に格納する
// 変換前後のマップデータはヌル文字で終端され、改行文字は含まない
//
// ※ 変換後、map1 の内容は変化しない。
//    但し、map1 と map2 の配列が同一の場合、変換後の map1 と map2 の内容は不定
//---------------------------------------------------------------------------------
int transformMap(int method, int n, char map1[][LINE_SIZE], char map2[][LINE_SIZE])
{
    int i, j;

    if (n >= LINE_SIZE) {
        return 0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){

            if (method == 1){ 				// 90度右回転
                map2[j][n-1-i] = map1[i][j];

            } else if (method == 2){ 		// 90度左回転
                map2[n-1-j][i] = map1[i][j];

            } else if (method == 3){ 		// 左右反転
                map2[i][n-1-j] = map1[i][j];

            } else if (method == 4){ 		// 上下反転
                map2[n-1-i][j] = map1[i][j];
            }
        }
    }

    // 各行の終端処理
    for (i = 0; i < n; i++){
        map2[i][n] = '\0';
    }

    return 1;
}