#include <stdio.h>
#include <hamakou.h>
main(){

    int data = getint("Input = ");

    if(data % 3 == 0){
        printf("Fizz");
    }
    if(data % 5 == 0){
        printf("Buzz");
    }

    if(data % 3 == 0 || data % 5 == 0){
        printf("\n");
    }

    return (0);
}