#include <stdio.h>
#include <hamakou.h>

main(){

    int i, sum = 0;
    for(i = 1; i <= 100; i += 2){
        sum += i;
    }
    printf("1から100までの奇数の和 ：%d\n",sum);

    return (0);
}