//008 - Num in Alphabet
//後付け
#include <stdio.h>

int main(){

    int i, y=0;

    char A[1000001];
    
    scanf("%s",A);

    for(i = 0; A[i] != '\0'; i++){

        if(A[i] > '9' ){

            y++;
        }
    }

    printf("%d\n",y);

    return 0;
}