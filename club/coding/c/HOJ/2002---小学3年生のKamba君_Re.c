//2002 - 小学3年生のKamba君_Re

#include <stdio.h>

int main(){

    char C[27];
    int x, y;
    char i;

    scanf("%s",C);
    x = 0;

    for( i ='a'; i < 'z'; i++ && x++){

        if(i != C[x]){

            y++;
        }
    }

    printf("%d\n",y);

    return 0;
}