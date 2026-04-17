#include <stdio.h>

int main(){

    int ans = 0, tmp = 0;
    char S[74000] = {};

        scanf("%s",&S);

    for(int i = 0; S[i] != '\0'; i++){

        if(S[i] == 'a' || S[i] == 'b' || S[i] == 'm' || S[i] == 'k'){

            ans++;
        }
        else{
            if(tmp < ans){
                tmp = ans;
            }
            ans = 0;
        }

    }
    if(tmp >= ans){
            ans = tmp;
        }
    printf("%d\n",ans);

    return 0;
}