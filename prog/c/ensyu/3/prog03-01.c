#include <stdio.h>
#include <hamakou.h>

main()
{
	char c[255], temp;
	int i, j, len;

	len = getstring("input: ", c);
	printf("入力文字列 = %s\n", c);

	i = 0;
	j = len-1;
	while (i < j){
		temp = c[i];
		c[i] = c[j];
		c[j] = temp;

		i++;
		j--;
	}
	printf("逆順文字列 = %s\n", c);

	return (0);
}
