#include <stdio.h>
#include <hamakou.h>

main()
{
	char c[255], temp;
	int i, j, len, p=1;

	len = getstring("input: ", c);
	printf("入力文字列 = %s\n", c);

	i = 0;
	j = len-1;
	while (i < j && c[i] == c[j]){
		i++;
		j--;
	}
	if(c[i] != c[j]){
		p = 0;
	}

	printf("p = %d\n", p);

	return (0);
}
