// 文字列⇒数値の変換
#include <iostream>
#include <string>
using namespace std;

int main() {
    // string から int型に変換します。
    string s = "123";
    
    // string 型から int 型に変換する。
    int num = stoi( s );
    
    //123 の 2倍 を出力する。
    cout << num * 2 << endl;

    return 0;
}