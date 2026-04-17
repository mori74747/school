#include <stdio.h>
#include <hamakou.h>

main()
{
	char c[255], temp;
	int i, len;

	len = getstring("input: ", c);

	i = 0;
	while (i < len){
		if('A' <= c[i] && c[i] <= 'Z'){
			c[i] += 32;
		}
		else if('a' <= c[i] && c[i] <= 'z'){
			c[i] -= 32;
		}
		i++;
	}

	printf("出力文字列 = %s\n", c);

	return (0);
}