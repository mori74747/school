#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    int sum, i = 1;

    while(i <= n){
        sum = sum + i;
        i = i + 1;
    }

    printf("0 ~ %dの整数和 = %d\n", n, sum);

    return (0);
}