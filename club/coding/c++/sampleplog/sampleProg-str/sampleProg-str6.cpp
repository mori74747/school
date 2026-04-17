// 部分文字列の取得
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 文字列を用意する。
    string s = "Hello Kamba Kun!!";
    
    // "Kamba Kun!!" だけ取り出したいと思います。
    /*
    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
    H  e  l  l  o     K  a  m  b  a     K  u  n  !  ! 
    
    6番目から11文字分切り取って、出力します。
    */

    string sub = s.substr ( 6, 11 );

    cout << "s.substr ( 6, 11 ) = " << sub << endl;

    return 0;
}