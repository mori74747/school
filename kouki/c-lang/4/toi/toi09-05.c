#include <stdio.h>
#include <hamakou.h>

main()
{
	int  n;                   // 入力文字列の数
	int  i;                   // ループ用
	int  a, b;                // a: 先頭から見ていく b: 末尾から見ていく
	char strData[100][256];   // 文字列格納用
	int  str_len[100];        // 文字列の長さ格納用

	// n の入力
	n = getint("入力する文字列の数: ");

	// 文字列の入力
	for(i = 0; i < n; i++){
		printf("文字列%d: ",i+1);
		str_len[i] = getstring("", strData[i]);
	}

	// 文字列を逆順にする
	for(i = 0; i < n; i++){
		a = 0;
		b  = str_len[i] - 1;

		char tmp; // 文字データの一時保存用
		while(a < b){
			tmp           = strData[i][a];
			strData[i][a] = strData[i][b];
			strData[i][b] = tmp;

			a++;
			b--;
		}
	}

	// 文字列の出力
	for(i = 0; i < n; i++){
		printf("文字列%dの逆順: %s\n",i+1, strData[i]);
	}
	return(0);
}
