#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hamakou.h"
#include "stack.h"

#define TRUMP_SIZE     53     // トランプ枚数（53以上はジョーカーを追加）
#define SHUFLE_COUNT   1000   // シャッフル回数
#define PILE_SIZE      10     // 2つ作る山の大きさ

void CardSet(int card[]);
void CreatePile(int card[], Stack* pile1, Stack* pile2);
void ShowResults(Stack* pile1, Stack* pile2);

char MarkCheck(int card);

main(){

    /*---トランプを格納する配列-----
        card[ 0-12] H:1-13
        card[13-25] D:1-13  
        card[26-38] S:1-13  
        card[39-51] C:1-13
        card[52]    J  
    -------------------------*/
    int card[53];

    Stack pile1, pile2;         // カードから作った山
    initStack(&pile1);          // スタックの初期化
    initStack(&pile2);

    int i;                      // カウンタ変数

    int card1;                  // プレイヤー1のカード
    int card2;                  // プレイヤー2のカード

    // よく切ったトランプを用意する
    CardSet(card);
    
    // 10枚の山を2つ作る
    CreatePile(card, &pile1, &pile2);
    
    // 1枚ずつめくって勝敗判定
    ShowResults(&pile1, &pile2);

    return (0);
}

/*-------------------------------------------------
[引 数] int card[]: トランプをセットする配列
[戻り値] なし
[機 能] カードをセットし、シャッフルする
-------------------------------------------------*/
void CardSet(int card[]){
    int i;      // カウンタ変数
    for(i = 0; i < TRUMP_SIZE; i++){
        card[i] = i;
    }

    int j, k;               // j,k: 発生した乱数を格納
    int temp;               // 一時保存用 

    srand(time(NULL));                      // 乱数の初期化 
    for (i = 0; i < SHUFLE_COUNT; i++) {
        j = rand() % TRUMP_SIZE;            // 0〜52の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
        k = rand() % TRUMP_SIZE;            // 0〜52の間の乱数を１つ発生(rand()は0以上の整数乱数を返す)　
        temp    = card[j];          // --+                         
        card[j] = card[k];          //   |- 2枚のカードを交換      
        card[k] = temp;             // --+                         
    }
    return;
}

/*-------------------------------------------------
[引 数] int card[] : もとのトランプの山
[　 　] Stack pile1: 作ったトランプの山1を格納するスタック
[　 　] Stack pile2: 作ったトランプの山2を格納するスタック
[戻り値] なし
[機 能] 上から指定した枚数選び、カードの山を作る
-------------------------------------------------*/
void CreatePile(int card[], Stack* pile1, Stack* pile2){

    int i = 0;    // カウンタ変数
    while(i < PILE_SIZE*2){
        push(pile1, card[i]);
        i++;
        push(pile2, card[i]);
        i++;
    }

    return;
}

/*-------------------------------------------------
[引 数] Stack pile1: 作ったトランプの山1
[　 　] Stack pile2: 作ったトランプの山2
[戻り値] なし
[機 能] トランプの山2つから、1枚ずつ捲ってゲームの結果を出力する
-------------------------------------------------*/
void ShowResults(Stack* pile1, Stack* pile2){
    int  card1;  // プレイヤー1のカード
    int  card2;  // プレイヤー2のカード
    int  num1;   // プレイヤー1のカードの数字
    int  num2;   // プレイヤー2のカードの数字
    char mark1;  // プレイヤー1のカードのマーク
    char mark2;  // プレイヤー2のカードのマーク
    char game;   // ゲームの勝敗 '<' or '>' or '='

    int point1 = 0;  // プレイヤー1の総得点
    int point2 = 0;  // プレイヤー2の総得点

    int i;      // カウンタ変数
    for(i = 1; i <= PILE_SIZE; i++){
        // 1枚ずつ取り出す
        pop(pile1, &card1);
        pop(pile2, &card2);

        printf("(%2d回目)",i);
        
        // マークのチェック
        mark1 = MarkCheck(card1);
        mark2 = MarkCheck(card2);

        num1 = card1 % 13 + 1;
        num2 = card2 % 13 + 1;

        if(mark1 == 'J' && mark2 == 'J'){
            game = '=';
            point1++;
            point2++;
        }else if(mark1 == 'J'){
            game = '>';
            point1 += 2;
        }else if(mark2 == 'J'){
            game = '<';
            point2 += 2;
        }else if(num1 > num2){
            game = '>';
            point1 += 2;
        }else if(num1 < num2){
            game = '<';
            point2 += 2;
        }else{
            game = '=';
            point1++;
            point2++;
        }

        // 表示
        // プレイヤー1
        printf("%9s", "Player1:");
        printf("%2c", mark1);

        if(mark1 != 'J'){
            printf("%s%2d%s","[",num1,"]");
        }else{
            printf("%4s", "");
        }

        // 結果
        printf("%2c", game);

        // プレイヤー2
        printf("%9s", "Player2:");
        printf("%2c", mark2);

        if(mark2 != 'J'){
            printf("%s%2d%s","[",num2,"]");
        }else{
            printf("%4s", "");
        }

        // 総得点
        printf("%11s%2s","総得点","-");

        printf("%9s", "Player1:");
        printf("%3d%s",point1,",");

        printf("%9s", "Player2:");
        printf("%3d",point2);

        printf("\n");
    }
    printf("\n");
    printf("%s%d\n","Player1の得点: ",point1);
    printf("%s%d\n","Player2の得点: ",point2);
    printf("\n");

    return;
}

/*-------------------------------------------------
[引 数] int : card
[戻り値] markを表すchar型の文字
[機 能] カードからマークを判別する
-------------------------------------------------*/
char MarkCheck(int card){
    char mark;
    if(0 <= card && card <= 12){
        mark = 'H';
    }
    else if(13 <= card && card <= 25){
        mark = 'D';
    }
    else if(26 <= card && card <= 38){
        mark = 'S';
    }
    else if(39 <= card && card <= 51){
        mark = 'C';
    }
    else if(card <= 52){
        mark = 'J';
    }

    return(mark);
}