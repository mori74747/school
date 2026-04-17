//1918 - 小学3年生のKamba君

#include <stdio.h>

int main(){

    int y = 0;
    char c, i;

    for(i = 'a'; i < 'z'; i++){

        scanf("%c ",&c );

        if(c != i){
            y++;
        }
    }
    printf("%d\n",y);

    return 0;
}