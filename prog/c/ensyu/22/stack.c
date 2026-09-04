#include <stdio.h>
#include <hamakou.h>
#include "stack.h"

int GetSP(Stack *s);
void SetSP(Stack *s, int data);
int GetStorage(Stack *s, int i);
void SetStorage(Stack *s, int i, int data);

/*-----操作関数-----*/

/*---------------------------------------
［機 能］     スタックを初期化し、空の状態にする
［引 数］s ： 初期化するスタック
---------------------------------------*/
void initStack(Stack *s){
    SetSP(s, 0);
}

/*---------------------------------------
［機 能］スタックにデータを格納する
［引 数］s    ： データの格納対象となるスタック
［　 　］data ： スタックｓへ格納するデータ
［戻り値］正常終了＝１，スタック・オーバーフロー＝０
---------------------------------------*/
int push(Stack *s, int data){
    if(GetSP(s) == STACK_SIZE){
        return(0);
    }else{
        int now_sp = GetSP(s);
        SetStorage(s, now_sp, data);
        SetSP(s, now_sp+1);
        return(1);
    }
}

/*---------------------------------------
［機 能］スタックからデータを取り出す
［引 数］s    ： データの取り出し対象となるスタック
［　 　］data ： スタックｓから取り出したデータ
［戻り値］正常終了＝１，スタック・アンダーフロー＝０
---------------------------------------*/
int pop(Stack *s, int *data){
        if(GetSP(s) == 0){
        return(0);
    }else{
        int now_sp = GetSP(s);
        *data = GetStorage(s, now_sp-1);
        SetSP(s, now_sp-1);
        return(1);
    }
}


/*-----アクセサー-----*/

/*---------------------------------------
［機 能］スタックポインタを返す
［引 数］s    ： データの取り出し対象となるスタック
［戻り値］スタックポインタの値
---------------------------------------*/
int GetSP(Stack *s){
    return(s->sp);
}

/*---------------------------------------
［機 能］スタックポインタを更新する
［引 数］s    ： データの格納対象となるスタック
［　 　］data ： スタックｓへ格納する新たなスタックポインタ
［戻り値］なし
---------------------------------------*/
void SetSP(Stack *s, int data){
    s->sp = data;
    return;
}

/*---------------------------------------
［機 能］指定した位置のstorageを返す
［引 数］s    ： データの取り出し対象となるスタック
［　 　］i    ： storageの指定位置
［戻り値］指定した位置のstorageの値
---------------------------------------*/
int GetStorage(Stack *s, int i){
    return(s->storage[i]);
}

/*---------------------------------------
［機 能］指定した位置のstorageを更新する
［引 数］s    ： データの格納対象となるスタック
［　 　］i    ： storageの指定位置
［　 　］data ： スタックｓへ格納する新たな値
［戻り値］なし
---------------------------------------*/
void SetStorage(Stack *s, int i, int data){
    s->storage[i] = data;
    return;
}

