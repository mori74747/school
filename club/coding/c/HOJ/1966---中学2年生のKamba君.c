//1966 - 中学2年生のKamba君

#include <stdio.h>

int main() {

    long long a,b,x,y;
    
    scanf("%lld%lld%lld", &a,&b,&x);

    y = (a + b)*(x - a);


    printf("%lld\n",y);

    return 0;
}