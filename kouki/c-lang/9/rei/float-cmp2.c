#include <stdio.h>
#include <math.h>
#include <float.h>

main()
{
    double a;
    double b;

    a = 0.6 - 0.4;
    b = 0.2;
    if (fabs(a - b) < DBL_EPSILON) {
        printf("(0.6 - 0.4) と 0.2 は等しい。\n");
    } else {
        printf("(0.6 - 0.4) と 0.2 は等しくない。\n");
    }

    return(0);
}
