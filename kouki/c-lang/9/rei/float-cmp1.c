#include <stdio.h>

main()
{
    double a;
    double b;

    a = 0.6 - 0.4;
    b = 0.2;
    if (a == b) {
        printf("(0.6 - 0.4) と 0.2 は等しい。\n");
    } else {
        printf("(0.6 - 0.4) と 0.2 は等しくない。\n");
    }

    return(0);
}
