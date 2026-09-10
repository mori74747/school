#include <stdio.h>
#include "hamakou.h"
#include "stack.h"

main(){

    int n;      // 入力する車両番号/0
    Stack s;    // 行き止まりの線路にいる車両 
    int data;   // 出力する車両番号

    initStack(&s);

    printf("車両番号または0を改行区切りで入力\n");
    while(scanf("%d", &n) != EOF){
        if(n == 0){
            pop(&s, &data);
            printf("%d\n", data);
        }else{
            push(&s, n);
        }
    }

    return (0);
}