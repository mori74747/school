#include <stdio.h>

int main() {

    int N;
    scanf("%d\n",&N);

    long long a[N];
    
    for(int i = 0; i < N; i++){

        scanf("%lld",&a[i]);
    }
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < N-1-i; j++){

            if(a[j] > a[j+1]){

                long long tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i = 0; i < N; i++){

        printf("%lld\n",a[i]);
    }

    return 0;
}