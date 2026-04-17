// 文字列の検索
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 文字列を入力する。
    string s;
    cout << "Input s = ";
    cin >> s;

    // 検索したい文字列を入力する。
    string f;
    cout << "Input Search String = ";
    cin >> f;

    // 検索して、あった場合は Yes, なかった場合は No を出力する。
    if ( s.find ( f ) == string::npos ) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}