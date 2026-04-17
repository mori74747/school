#include <stdio.h>
#include <sc0.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;
# define SC_L 20 // 格子の x および y 軸方向の長さ L
# define SC_SC 100 // ひずみの臨界値 Sc
# define SC_alpha 0.20 // αの値 ((2) 式参照)
# define SC_t 10 // 下にあたえられるひずみの時刻 t
# define SC_A 10.0 // 評価関数 E のパラメータ A

int main(){

    double E;
    int SC_Ne; // 問題の地震の回数 Ne を格納する整数
    int SC_Sf[SC_L+1][SC_L+1]; // 問題の時刻 t でのひずみを格納する 2 次元整数配列
    int SC_S0[SC_L+1][SC_L+1]; // 解答を格納する 2 次元整数配列

    SC_input;

    

    return 0;
}