#include <stdio.h>

main()
{
    float sum;
    int i;

    sum = 0;
    for (i = 1; i <= 9999; i++) {
        sum = sum + 1.0 / (i * (i + 1.0));
    }
    printf("大きい方からの和 = %g\n", sum);

    sum = 0;
    for (i = 9999; i >= 1; i--) {
        sum = sum + 1.0 / (i * (i + 1.0));
    }
    printf("小さい方からの和 = %g\n", sum);

    return(0);
}
