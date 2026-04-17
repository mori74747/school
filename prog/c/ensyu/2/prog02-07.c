#include <stdio.h>
#include <hamakou.h>
main(){

    float x = getfloat("Input x: ");
    int n = getint("Input n: ");
    float fac = 1;
    int i = 1;

    while(i <= n){
        fac = fac * x;
        i = i + 1;
    }
    printf("%g^%d = %g\n", x, n, fac);

    return (0);
}