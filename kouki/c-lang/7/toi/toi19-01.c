#include <stdio.h>

int main(int argc, char *argv[]){
    int i;              //  カウンタ変数
    int count;          //  個数の受け取り変数
    char name = "";     //  商品名の格納用変数
    int prise;          //  商品値段の格納用変数
    int total = 0;      //  合計金額格納用変数
    int tax;            //  消費税格納用変数

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
            if(argv[i][1] >= '0' && argv[i][1] <= '9'){
                sscanf(&argv[i][1], "%d", &tax);
                break;
            }
            switch(argv[i][1]){
                case 'a':
                    name = "りんご";
                    prise = 100;
                    break;
                case 'b':
                    name = "ばなな";
                    prise = 30;
                    break;
                case 'c':
                    name = "さくらんぼ";
                    prise = 200;
                    break;
                case 'd':
                    name = "どんぐり";
                    prise = 50;
                    break;
                case 'e':
                    name = "えび";
                    prise = 1000;
                default:
                    printf("オプションとして使用できません。\n");
            }
            sscanf(&argv[i][2], "%d", &count);
            i++;
        }
    }
    return (0);
}
