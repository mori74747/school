#include <stdio.h>
#include <hamakou.h>
main(){

    int m = getint("Input 行数: ");
    int n = getint("Input 列数: ");
    int i, j;

    i = 0;
    while(i < m){
        j = 0;
        while(j < n){
            printf("*");
            j = j + 1;
        }
        printf("\n");
        i = i + 1;
    }

    return (0);
}