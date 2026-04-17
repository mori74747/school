#include <iostream>

using namespace std;

int main () {
    int a;

    // a の値を入力する。
    cout << "Input a : ";
    cin >> a;

    // auto 型を使用する。
    auto b = a;

    // b の中身を 20 に変えてみる。
    b = 20;

    // a と b を出力してみる。
    cout << a << " " << b << endl;

    // auto& 型を使用する。
    auto& c = a;
    
    // c の中身を 30 に変えてみる。
    c = 30;

    cout << a << " " << c << endl;
    
    return ( 0 );
}