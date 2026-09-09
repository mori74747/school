#include <stdio.h>
#include <hamakou.h>

main(){

    int i = 2, sum = 0;
    do {
        sum += i;
        i += 2;
    }while(i <= 100);
    printf("1から100までの偶数の和 ：%d\n",sum);

    return (0);
}