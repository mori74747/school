#include <stdio.h>

main()
{
    int i;
    float s, work, loss, d;

    s = loss = 0;
    for (i = 0; i < 10000; i++) {
        work = s;
        d = 0.1 + loss;
        s = s + d;
	loss = d - (s - work);
    }

    printf("0.1を10000回加えると、%gになる。\n", s);

    return(0);
}
