#include <stdio.h>
#include <hamakou.h>

main(){

    int i = 1, sum = 0;
    while(i <= 100){
        sum += i;
        i += 2;
    }
    printf("1から100までの奇数の和 ：%d\n",sum);

    return (0);
}