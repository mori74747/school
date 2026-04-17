// 結合
#include <iostream>
#include <string>
using namespace std;

int main() {
    // s に "s = " と入れる。
    string s = "s = ";
    
    // s に 入力した追加したい文字列を入力する。
    string add;
    cin >> add;

    // s に追加したい文字列を += で結合！
    s += add;
    
    // 出力
    cout << s << endl;

    return 0;
}