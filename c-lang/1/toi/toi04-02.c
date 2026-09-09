#include <stdio.h>

main(){

    int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7;

    a += 5;
    b += c + 2;
    d += -e + 1;
    f *= (-g + 4);

    printf("a = %d\n",a);
    printf("b = %d\n",b);
    printf("d = %d\n",d);
    printf("f = %d\n",f);

    return (0);
}