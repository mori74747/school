#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];

    int max = -1;
    int max2 = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[max]) {
            max = i;
            max2 = i;
        } else if (i-1 == max2 && a[i-1] == a[i]) {
            max2 = i;
        }
    }

    int ok = 1;
    for (int i = 1; i < max; i++) {
        if (a[i] < a[i-1]) {
            ok = 0;
        } 
    }

    int ok2 = 1;
    for (int i = max2+1; i < n; i++) {
        if (a[i] > a[i-1]) {
            ok2 = 0;
        } 
    }

    if (max != 0 && max2 != n-1 && ok == 1 && ok2 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}