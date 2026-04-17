//後書き（自分自身)
#include <stdio.h>

int main(){

    int N,Q;
    scanf("%d%d",&N,&Q);

    int ID[740000] = {}, X[Q];
    int num;

    for(int i = 0; i < N; i++){

        scanf("%d",&num);
        ID[num] = 1;
    }
    for(int i = 0; i < Q; i++){

        scanf("%d",&X[i]);
        
        if(ID[X[i]] == 1){

            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}