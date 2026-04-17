// 文字列の長さの取得
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 文字列を入力する。
    string s;

    cout << "Input s = ";
    cin >> s;

    //  文字列の長さを取得する。
    int len = s.size();

    // 文字列の長さを出力する。
    cout << "s.length = " << len << endl;

    return 0;
}