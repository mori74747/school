#include <stdio.h>

int main(){

    int N, i;
    scanf("%d\n",&N);

    int M[N];

    for(i = 0; i < N; i++){

        scanf("%d\n",&M[i]);

        switch( M[i] ){

            case 1:
                printf("Curry\n");
                break;
            case 2:
                printf("Kraage\n");
                break;
            case 3:
                printf("Steak\n");
                break;
            case 4:
                printf("Ice Cream\n");
                break;
            case 5:
                printf("Coffee\n");
                break;
        }
        
    }


    return 0;
}