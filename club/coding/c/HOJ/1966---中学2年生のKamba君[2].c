//1966 - 中学2年生のKamba君

#include <stdio.h>

int main() {

    long long a, b, x, ans;

    scanf("%lld%lld%lld",&a,&b,&x);

    ans = 0;
    ans+= a + b;
    ans*= x - a;


    printf("%lld\n",ans);

    return 0;

}