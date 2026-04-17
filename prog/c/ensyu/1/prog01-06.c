#include <stdio.h>
#include <hamakou.h>
main(){

    int a = getint("Input a = ");
    int b = getint("Input b = ");

    int sum = a - b;

    if(sum < -10 || sum > 10){
        printf("差は11以上です\n");
    }else{
        printf("差は10以下です\n");
    }


    return (0);
}
