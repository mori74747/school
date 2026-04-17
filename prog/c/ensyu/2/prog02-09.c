#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    int odd = 0, even = 0, i = 1;

    while(i <= n){
        if(i % 2 == 1){
            odd = odd + i;
        }else{
            even = even + i;
        }
        i = i + 1;
    }
    printf("偶数の和 = %d\n",even);
    printf("奇数の和 = %d\n",odd);

    return (0);
}