//1967 - お絵描き中のKamba君

#include <stdio.h>

int main(){

    int i, N, Left;
    
    scanf("%d%d",&N,&Left);

    if(Left == -1){

        for(i = 0; i != N; i++){
            printf("=");
        }
        printf(">\n");
    }

    if(Left == 0){
        printf("<");

        for(i = 0; i != N; i++){
            printf("=");
        }
        printf("\n");
    }

    return 0;
}