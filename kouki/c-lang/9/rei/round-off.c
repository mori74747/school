#include <stdio.h>

main()
{
    long int i;
    float s;

    s = 0;
    for (i = 0; i < 10000; i++) {
        s = s + 0.1;
    }
    printf("0.1を10000回加えると、%gになる。\n", s);

    return(0);
}
