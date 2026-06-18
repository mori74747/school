#include <stdio.h>

void input(int n);
int  sum(int data[]);

int n;
int data[1000];

main(){

    char buff[256];
    printf("データ個数: ");
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d", &n);

    input(n);

    int data_sum = sum(data);
    int data_avg = data_sum / n;

    printf("合計: %d\n", data_sum);
    printf("平均: %d\n", data_avg);
}