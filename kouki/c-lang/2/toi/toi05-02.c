#include <stdio.h>
#include <hamakou.h>

main(){

    int a = getint("Input a: ");
    if(a < 0){
        printf("aは負数\n");
    }else if(a < 100){
        printf("aは0以上100未満\n");
    }else{
        printf("aは100以上\n");
    }

    return (0);
}