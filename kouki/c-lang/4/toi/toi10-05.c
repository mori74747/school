// [CTRL+D]キーが押されるまでに入力した文字の行数を数える  

#include <stdio.h>

main()
{
	// char c;
	// getcharの戻り値を受け取る変数はint型である必要がある
	// intでないと、EOFは判定できない
	int c;

	long lines = 0L;

	// while(c == getchar() != EOF){
	// cにgetcharで入力を受け取ってEOFかどうか判定するため、イコールが2つの比較でなく、
	// イコールが1つの代入をしてからEOFとの比較をする。
	// 演算順序は代入を先に行うよう、括弧をつける。
	while((c = getchar()) != EOF){
		// if (c = "\n")
		// イコールが1つでは代入処理になる。比較はイコールが2つ必要
		// cは文字をint型で受け取っている状態なので、比較は文字列でなく文字でint型として行う。
		if (c == '\n'){
			lines++;
		}
	}
	// printf("Lines = %d\n", lines);
	// long型は%dでは表示できない
	printf("Lines = %ld\n", lines);

	return(0);
}
