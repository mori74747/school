// 数値⇒文字列の変換
#include <iostream>
#include <string>
using namespace std;

int main() {
    // int から string に変換する。
    int num = 123;
    
    // int 型から string 型に変換する。
    string s = to_string ( num );

    for ( int i = 0; i < s.size(); i++ ) {
        cout << "s[" << i << "] = " << s[i] << endl; 
    }

    return 0;
}