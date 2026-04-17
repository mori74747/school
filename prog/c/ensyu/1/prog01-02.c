#include <stdio.h>
#include <hamakou.h>

main(){

    int a, b, c, d, max, min;

    a = getint("a = ");
    b = getint("b = ");
    c = getint("c = ");
    d = getint("d = ");

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
    if(d > max){
        max = d;
    }else if(d < min){
        min = d;
    }
    printf("max = %d min = %d \n",max,min);

    return (0);
}