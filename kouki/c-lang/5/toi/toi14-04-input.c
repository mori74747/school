#include <stdio.h>

extern int n;
extern int data[1000];

void input(int n){

    char buff[256];
    for(int i = 0; i < n; i++){
        printf("data[%d]: ", i);
        fgets(buff, sizeof(buff), stdin);
        sscanf(buff, "%d", &data[i]);
    }

    return;
}