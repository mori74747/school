#include <stdio.h>
#include <hamakou.h>

main(){

    int a, b, c, max, min;

    a = getint("a = ");
    b = getint("b = ");
    c = getint("c = ");

    if(a > b){
        max = a;
        min = b;
    }else{
        max = b;
        min = a;
    }
    if(c > max){
        max = c;
    }else if(c < min){
        min = c;
    }
    printf("max = %d min = %d \n",max,min);

    return (0);
}