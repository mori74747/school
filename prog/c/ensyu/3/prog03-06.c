#include <stdio.h>
#include <hamakou.h>

main()
{
	char a[255], b[255];
	int i, lenA, lenB;

	lenA = getstring("input a : ", a);
	lenB = getstring("input b : ", b);
	i = 0;
	while (i < lenA && a[i] == b[i]){
		i++;
	}

	printf("一致文字数 = %d\n", i);

	return (0);
}