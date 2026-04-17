#include <stdio.h>
#include <hamakou.h>
main(){

    int n = getint("Input n: ");
    int i = 1, hantei = 0;

    while(i <= n){
        printf("%d",i);
        int Fizz = i;
        if(Fizz % 3 == 0){
            hantei = 1;
        }else{
            while(Fizz != 0 && Fizz % 10 != 3){
                Fizz = Fizz / 10;
            }
            if(Fizz != 0){
                hantei = 1;
            }
        }
        if(hantei == 1){
            printf(" アホ");
        }
        printf("\n");
        i = i + 1;
        hantei = 0;
    }

    return 0;
}