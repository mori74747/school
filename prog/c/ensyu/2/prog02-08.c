#include <stdio.h>
#include <hamakou.h>
main(){

    int m = getint("Input m: ");
    int n = getint("Input n: ");

    int Fizz = 0, Buzz = 0, FizzBuzz = 0;
    int i = m;
    while(i <= n){
        if(i != 0){
            if(i % 15 == 0){
                FizzBuzz = FizzBuzz + 1;
                Fizz = Fizz + 1;
                Buzz = Buzz + 1;
            }
            else if(i % 3 == 0){
                Fizz = Fizz + 1;
            }
            else if(i % 5 == 0){
                Buzz = Buzz + 1;
            }
        }
        i = i + 1;   
    }
    printf("3の倍数： %d個\n", Fizz);
    printf("5の倍数： %d個\n", Buzz);
    printf("3と5の公倍数： %d個\n", FizzBuzz);
    return 0;
}