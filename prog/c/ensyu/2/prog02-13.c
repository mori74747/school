#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input 段数: ");
    int i, j;

    i = 0;
    while(i < n){
        j = 0;
        while(j <= i){
            printf("*");
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }
    
    return (0);
}