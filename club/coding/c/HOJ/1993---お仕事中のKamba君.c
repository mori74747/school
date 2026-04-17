// 1993 - お仕事中のkamba君

#include <stdio.h>

int main(){

    int N, i, a=0, b=0, c=0, d=0;

    scanf("%d\n",&N);

    char C[N];

    for(i = 0; i < N; i++){

        if(i == N - 1){

            scanf("%c",&C[i]);
        }
        else{   
            scanf("%c\n",&C[i]);
        }

        switch(C[i]){

            case 'A':
            a++;
            break;

            case 'B':
            b++;
            break;

            case 'C':
            c++;
            break;

            default:
            d++;
            break;
            }

        
    }

    printf("%d %d %d %d\n",a,b,c,d);

    return 0;
}