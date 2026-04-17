#include <stdio.h>
#include <hamakou.h>

main()
{
	char a[255], c;
	int i, len, p = -1;

	len = getstring("Input a : ", a);
	c = getcharacter("Input c : ");

	i = 0;
	while (i < len && a[i] != c){
		i++;
	}
	if(a[i] == c){
		p = i;
	}
	printf("文字検索結果 = %d\n", p);

	return (0);
}