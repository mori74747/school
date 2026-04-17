#include <stdio.h>
#include <hamakou.h>

main()
{
	char c[255], temp;
	int i, j, len;
	int eidai = 0, eiko = 0, kigou = 0, suuji = 0;

	len = getstring("input: ", c);

	i = 0;
	while (i < len){
		if('A' <= c[i] && c[i] <= 'Z'){
			eidai++;
		}
		else if ('a' <= c[i] && c[i] <= 'z'){
			eiko++;
		}
		else if ('0' <= c[i] && c[i] <= '9'){
			suuji++;
		}else{
			kigou++;
		}
		i++;
	}

	printf("大文字数 ： %d\n", eidai);
	printf("小文字数 ： %d\n", eiko);
	printf("数字の数 ： %d\n", suuji);
	printf("記号の数 ： %d\n", kigou);

	return (0);
}
