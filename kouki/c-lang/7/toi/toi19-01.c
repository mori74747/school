#include <stdio.h>

int main(int argc, char *argv[]){
  int i;              //  カウンタ変数
  int count;          //  商品の個数
  char *name = "";    //  商品名
  int prise;          //  商品値段
  int goukei;         //  その商品の合計金額
  int total = 0;      //  合計金額
  int tax = 0;        //  消費税

  //  オプションの有無・正誤のチェック  
  if(argc <= 1 || argv[1][0] != '-'){
    printf("オプションがないかまたは不正です。\n");
    printf("正しく入力して下さい。\n");
  }else{
    printf("--------------------------------------\n");
    /*
    *  オプションをチェックするループ
    *    コマンドラインの引数をすべて調べつくすか、
    *    またはハイフンのないオプションにであったら
    *    ループから抜ける
    */
    i = 1;  //  カウンタ変数の初期化
    while(argc > i && argv[i][0] == '-' ){
      // 消費税入力の判定
      if(argv[i][1] >= '0' && argv[i][1] <= '9'){
        sscanf(&argv[i][1], "%d", &tax);
      }else{
        //  商品判別
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
            name = "にんじん";
            prise = 200;
            break;
          case 'd':
            name = "どんぐり";
            prise = 50;
            break;
          case 'e':
            name = "えんぴつ";
            prise = 1000;
            break;
          default:
            printf("オプションとして使用できません。\n");
        }
        //  個数の入力
        sscanf(&argv[i][2], "%d", &count);
        //  統計に加算
        goukei = prise * count;
        total += goukei;

        //  表示
        printf("%11s%5s%5d%5s%4d%3s%8d\n",name,"@",prise,"×",count,"=",goukei);
      }
      i++;
    }
    //  統計表示
    printf("--------------------------------------\n");
    printf("%11s%29d\n","小　計",total);
    printf("%11s%29d\n","消費税",total*tax/100);
    printf("======================================\n");
    printf("%11s%29d\n","合　計",total+(total*tax/100));
  }
  return (0);
}
