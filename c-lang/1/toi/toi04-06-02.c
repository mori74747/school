#include <stdio.h>

main(){

    long hankei = 6400;
    double pai = 3.14159;

    printf("表面積 = %.3e km^2\n",4 * pai * (hankei * hankei));
    printf("体積   = %.3e km^3\n", pai * (hankei * hankei * hankei) *4/3);
    printf("静止衛星の速度 時速 %.3e km\n",((hankei+36000)*2*pai)/24);

    return (0);
}