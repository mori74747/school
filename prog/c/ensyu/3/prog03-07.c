#include <stdio.h>
#include <hamakou.h>

main()
{
	char a[1023], c;
	int i, len, k;

	len = getstring("文字列： ", a);
	k = getint("キー　： ");

	int Min = ' ';
	int Max = '~';

	int hanni = Max - Min + 1;

	i = 0;
	while (i < len){
		int add = (a[i] - Min + k) % hanni;

		if(add < 0){
			add += hanni;
		}
		a[i] = add + Min;

		i++;
	}

	printf("暗号　： %s\n", a);

	return (0);
}