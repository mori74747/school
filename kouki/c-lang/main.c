#include <stdio.h>
#include <hamakou.h>


main(){

    int x[5] = {'a','b','c','d','\0'};
	int y[5] = "abcd";
	
	for(int i = 0; i < 4; i++) printf("%d ",x[i]);
	printf("\n");
	printf("%s\n%s\n",x,y);

    return (0);
}