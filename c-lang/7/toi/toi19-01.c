#include <stdio.h>

int main(int argc, char *argv[]){
    int i;  //  カウンタ変数  

    //  オプションの有無・正誤のチェック  
    if(argc <= 1 || argv[1][0] != '-'){
        printf("オプションがないかまたは不正です。\n");
        printf("正しく入力して下さい。\n");
    }else{
        /*
        *  オプションをチェックするループ
        *    コマンドラインの引数をすべて調べつくすか、
        *    またはハイフンのないオプションにであったら
        *    ループから抜ける
        */
        i = 1;  //  カウンタ変数の初期化  
        while(argc > i && argv[i][0] == '-' ){
            switch(argv[i][1]){
                case 'a':
                    printf("りんご\n");
                    break;
                case 'b':
                    printf("バナナ\n");
                    break;
                case 'c':
                    printf("さくらんぼ\n");
                    break;
                case 'd':
                    printf("L");
                    break;
                default:
                    printf("オプションとして使用できません。\n");
            }
            i++;
        }
    }
    return (0);
}
