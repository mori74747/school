#include <stdio.h>

void ast(int n);
main()
{
    int  n;
    char buff[256];
    
    printf("*の個数: ");
    fgets(buff, sizeof(buff), stdin);
    sscanf(buff, "%d", &n);

    ast(n);

}

// [引  数] int型: n
// [戻り値] なし
// [動  作] n文字の*を一列に表示。最後に改行する。
void ast(int n){
    // n文字の*を表示
    for(int i = 0; i < n; i++){
        printf("*");
    }
    printf("\n");
}