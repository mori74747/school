//003-数の分類

#include <stdio.h>

int main(){

    int A;

    scanf("%d",&A);

    A = A % 2;

    if (A == 1){

        printf("luke\n");

    }else if(A == 0){

        printf("leia\n");
    }

    return 0;
}