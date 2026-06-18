#include <stdio.h>

extern int n;
extern int data[1000];

int sum(int data[]){

    int data_sum = 0;
    for(int i = 0; i < n; i++){
        data_sum += data[i];
    }

    return(data_sum);
}