#include <stdio.h>
#include <string.h>

#define LINE_SIZE 51 // マップを格納する2次元配列のヌル文字を含む行サイズ

int readMap(                     );
int showMap(                            );
int transformMap(                                                                 );

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
int transformMap(                                                                 )
{
}