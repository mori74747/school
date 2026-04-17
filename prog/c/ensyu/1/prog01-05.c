#include <stdio.h>
#include <hamakou.h>
main(){

    int a = getint("Input a = ");
    int b = getint("Input b = ");
    int c = getint("Input c = ");

    if(a == b && b == c){
        printf("3つの値は等しいです\n");
    }else if(a != b && a != c && b != c){
        printf("3つの値は異なります\n");
    }else{
        printf("2つの値が等しいです\n");
    }

    return (0);
}