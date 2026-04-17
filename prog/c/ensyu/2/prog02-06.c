#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    int fac = 1, i = 2;

    while(i <= n){
        fac = fac * i;
        i = i + 1;
    }
    printf("%d! = %d\n", n, fac);

    return (0);
}