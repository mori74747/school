// 009- a+b+c
//後付け
#include <stdio.h>

int main(){

    int A, B, C, a, b, c, ans;

    scanf("%d%d%d",&A,&B,&C);

    ans = A + B + C;

    if( 9 < ans && ans < 100){

        a = ans / 10;
        b = ans % 10;

        ans = a + b;

    }else if(ans > 99){

        a = ans / 100;
        b = ans % 100;
        
        if(b > 9){
            
            c = b % 10;
            b = b / 10;

            ans = a + b + c;
        }
        else{

            ans = a + b;
        }

    }
    printf("%d\n",ans);

    return 0;
}