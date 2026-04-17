#include <stdio.h>

int main(){

    int Q;
    scanf("%d",&Q);

    int Query[Q][2];
    int A[1000000];
    int stack=0,count=0;
    
    for(int i = 0; i < Q; i++){
        scanf("%d%d",&Query[i][0],&Query[i][1]);
    }
    for(int i = 0; i < Q; i++){
        if(Query[i][0] == 1){
            A[stack] = Query[i][1];
            stack++;
        }
        else if(Query[i][0] == 2){
            for(int j = 0; j < Query[i][1]; j++){
                
                printf("%d\n",A[count]);
                count++;
            }
        }
        else if(Query[i][0] == 3){
            for(int j = 0; j < Query[i][1]; j++){
                
                int tmp = A[count];
                A[count] = 0;
                A[stack] = tmp;
                count++;
                stack++;
            }
        }
    }
    return 0;
}