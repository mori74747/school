// 置き換え
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 文字列を用意する。
    string s = "Hello World Kun!!";
    
    // 元の文字列
    cout << "s = " <<  s << endl;

    // "World" を "Kamba" に変更したいと思います。
    /*
    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
    H  e  l  l  o     W  o  r  l  d     K  u  n  !  ! 
    
    6番目から5文字を Kamba に変えます。
    */

    s.replace ( 6, 5, "Kamba" );

    cout << "s.replace ( 6, 5, \"Kamba\" ) = " << s << endl;

    return 0;
}