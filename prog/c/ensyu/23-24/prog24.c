#include <stdio.h>
#include "hamakou.h"
#include "stack.h"

#define TRUMP_SIZE     53     // トランプ枚数（53以上はジョーカーを追加）
#define SHUFLE_COUNT   1000   // シャッフル回数
#define PILE_SIZE      10     // 2つ作る山の大きさ

void CardSet(int card[]);
void CreatePile(int card[], Stack* pile1, Stack* pile2);
void ShowResults(Stack* pile1, Stack* pile2);

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
        card[i] = i+1;
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
}

/*-------------------------------------------------
[引 数] int card[] : もとのトランプの山
[　 　] Stack pile1: 作ったトランプの山1を格納するスタック
[　 　] Stack pile2: 作ったトランプの山2を格納するスタック
[戻り値] なし
[機 能] 上から指定した枚数選び、カードの山を作る
-------------------------------------------------*/
void CreatePile(int card[], Stack* pile1, Stack* pile2){

    int i = 0;               // カウンタ変数
    while(i < PILE_SIZE*2){
        push(pile1, card[i]);
        i++;
        push(pile2, card[i]);
        i++;
    }
}

/*-------------------------------------------------
[引 数] Stack pile1: 作ったトランプの山1
[　 　] Stack pile2: 作ったトランプの山2
[戻り値] なし
[機 能] トランプの山2つから、1枚ずつ捲ってゲームの結果を出力する
-------------------------------------------------*/
void ShowResults(Stack* pile1, Stack* pile2){
    int card1;  // プレイヤー1のカード
    int card2;  // プレイヤー2のカード

    int i;      // カウンタ変数
    for(i = 1; i <= PILE_SIZE; i++){
        pop(&pile1, card1);
        pop(&pile2, card2);

        printf("(%2d回目)%9s",i,"Player1:");
        if(card1 >= 53){
            
        }
        
    }
    
}