#include <stdio.h>
#include <hamakou.h>

void chLine(char c, int n);
void chRectangle(char c, int m, int n);
void chTriangle(char c, int m);

int main(void)
{
	// 変数の宣言・入力
	int m, n;
	char c;

	n = getint("列数: ");
	m = getint("行数: ");

	// 長方形
	c = getcharacter("長方形を描く文字: ");
	printf("\n");
	chRectangle(c, m, n);

	// 三角形
	c = getcharacter("三角形を描く文字: ");
	printf("\n");
	chTriangle(c, m);

	return(0);
}

/*-----chLine-----
[引　数]　文字c, 整数n
[戻り値]　なし
[機　能]　第1引数で指定した文字cを、第2引数で指定した数だけ横1列に
表示する。ただし、表示後に改行はしない。
------------------*/
void chLine(char c, int n){
	int i;
	for(i = 1; i <= n; i++){
		printf("%c",c);
	}
	return;
}

/*-----chRectangle-----
[引　数]　文字c, 整数m, n
[戻り値]　なし
[機　能]　第1引数で指定した文字cを、第2、第3引数で指定したm行n列の
長方形を表示する。ただし、表示後に改行をする。
------------------*/
void chRectangle(char c, int m, int n){
	int i;
	for(i = 1; i <= m; i++){
		chLine(c, n);
		printf("\n");
	}
	return;
}

/*-----chTriangle-----
[引　数]　文字c, 整数m
[戻り値]　なし
[機　能]　第1引数で指定した文字cを、第2引数で指定したm段の二等辺三角形を
表示する。ただし、表示後に改行する。
------------------*/
void chTriangle(char c, int m){
	int i;
	for(i = 1; i <= m; i++){
		chLine(' ', m-i);
		chLine(c, i*2-1);
		chLine(' ', m-i);
		printf("\n");
	}
	return;
}