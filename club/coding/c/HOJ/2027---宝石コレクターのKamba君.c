#include <stdio.h>

int main(){

    int N,M,k,ct=0;
    long long G,search;
    scanf("%d",&N);
    long long count[100000] = {};

    for(int i = 0; i < N; i++){
        scanf("%d",&M);
        for(int j = 0; j < M; j++){
            
            scanf("%lld",&G);

            while(k == 0){
                long long left=0,right=50000;
                if(G <= right){
                    right /= 2;
                }else{
                    long long temp = right;
                    left = right;
                    right = temp/2;
                }
                if(right == left+1){
                    k++;
                    search = left;
                }
            }
            if(count[ct] == 0){
                
            }else{
                ct--;
            }
            ct++;
        }
    }
    printf("%d\n",ct);

    return 0;
}