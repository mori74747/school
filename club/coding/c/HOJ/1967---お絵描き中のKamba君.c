//1967 - お絵描き中のKamba君

#include <stdio.h>

int main() {

    int Left, N, a, b;

    a = 0, b = 0;

    scanf("%d%d",&N,&Left);
    
    if(Left == -1){

        while(N > a){

            a++;
            printf("=");

        }   printf(">\n");

    }else if(Left == 0){
        printf("<");
        while(N > b){
            
            b++;
            printf("=");

        }   printf("\n");
    }

    return 0;
}