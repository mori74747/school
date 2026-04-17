// 参照型
#include <iostream>

using namespace std;

int main () {
    int a;

    // a の値を入力する。
    cout << "Input a : ";
    cin >> a;

    // int&（=intの参照型）の b を宣言する。
    // b の中には a の場所が格納される。
    int& b = a;

    // この状態で a と b を出力してみると...
    cout << a << " " << b << endl;

    
    // b を 20 に変えてみる。
    b = 20;

    // この状態で a と b を出力してみると...
    cout << a << " " << b << endl;


    // a を 30 に変えてみる。
    a = 30;

    // この状態で a と b を出力してみると...
    cout << a << " " << b << endl;

    return ( 0 );
}