#include <stdio.h>
#include <hamakou.h>

main()
{
    int a;
    a = getint("整数 a = ");

    switch(a % 2){
        case 0:
            printf("データは偶数です。\n");     // a が偶数 
            break;
        default:
            printf("データは奇数です。\n");     // a が奇数 
    }
    return(0);
}
