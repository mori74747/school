// 局所変数と大域変数がちゃんと使えることを確かめてください。
#include <iostream>
#define endl "\n";
using namespace std;

int x = 10;

int main () {
    int y = 30;
    cout << x << y << endl;

    x = 20;
    cout << x << y << endl;

    y = 40;
    cout << x << y << endl;

    x = y;
    cout << x << y << endl;

    return ( 0 );
}