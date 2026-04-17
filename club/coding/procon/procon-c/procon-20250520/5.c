//005- 3-number
//後付け
#include <stdio.h>

int main(){

    int A, B, C;

    scanf("%d%d%d",&A,&B,&C);

    if(A > B && A > C){
    
        printf("%d",A);
    }
    else if(B > C){
        
        printf("%d",B);
    }
    else{
        printf("%d",C);
    }

    return 0;
}


/*

int main(){

    if(A > B && A > C){
    
        printf("%d",A);
    }
    else if(B > C){
        
        printf("%d",B);
    }
    else{
        printf("%d",C);
    }













    return 0;


    if(A > B){

        if(A > C){
            printf("%d\n",A);
        }
        else{
            printf("%d\n",C);
        }
    }
    else if(B > A){

        if(B > C){

            printf("%d\n",B);
        }
        else{

            printf("%d\n",C);
        }

    }
    else{
        printf("%d\n",A);
    }

}

















*/