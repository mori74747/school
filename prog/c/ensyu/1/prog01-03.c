#include <stdio.h>
#include <hamakou.h>

main(){

    int a, b, c, max, min, mid;

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
        mid = max;
        max = c;
    }else if(c < min){
        mid = min;
        min = c;
    }else{
        mid = c;
    }
    printf("max = %d min = %d mid = %d\n",max,min,mid);

    return (0);
}