#include <stdio.h>
#include <hamakou.h>

void chLine(char c, int n);
void chRectangle(char c, int m, int n);
void chTriangle(char c, int m);

int main(void)
{
	int m, n;
	char c;

	n = getint("列数: ");
	m = getint("行数: ");

	c = getcharacter("長方形を描く文字: ");
	printf("\n");
	chRectangle(c, m, n);

	c = getcharacter("三角形を描く文字: ");
	printf("\n");
	chTriangle(c, m);

	return(0);
}

void chLine(char c, int n){
	int i;
	for(i = 1; i <= n; i++){
		printf("%c",c);
	}
}

void chRectangle(char c, int m, int n){
	int i;
	for(i = 1; i <= n; i++){
		chLine(c, m);
		printf("\n");
	}
}

void chTriangle(char c, int m){
	int i;
	for(i = 1; i <= m; i++){
		chLine(' ', m-i);
		chLine(c, i*2-1);
		chLine(' ', m-i);
		printf("\n");
	}	
}