#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    int evensum = 0, i = 0, a[100];

    while(i < n){
        printf("a[%d] = ",i);
        a[i] = getint("");
        i = i + 1;
    }
    i = 0;
    while(i < n){
        if(a[i] % 2 == 0){
            evensum = evensum + a[i];
        }
        i = i + 1;
    }
    printf("偶数データの和 = %d\n",evensum);

    return (0);
}