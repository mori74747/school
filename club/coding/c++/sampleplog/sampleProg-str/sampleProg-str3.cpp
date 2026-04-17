// 比較
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 文字列を 2 つ受け取る。
    string s, t;
    cin >> s >> t;

    // 受け取った 2 つの文字列について、以下の比較をする。
    // 等しいか等しくないか
    if ( s == t ){
        cout << "s = t" << endl;
    } else {
        cout << "s != t" << endl;
    }

    // s < t が成り立つかどうか。
    if ( s < t ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}