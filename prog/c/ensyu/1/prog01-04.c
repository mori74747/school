#include <stdio.h>
#include <hamakou.h>
main(){

    int data = getint("Input = ");

    if(data % 4 != 0){
        printf("平年\n");

    }else if(data % 100 != 0){
        printf("うるう年\n");

    }else if(data % 400 != 0){
        printf("平年\n");

    }else{
        printf("うるう年\n");
    }


    return (0);
}