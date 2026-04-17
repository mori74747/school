// アクセスと変更
#include <iostream>
#include <string>
using namespace std;

int main() {
    // あえて、スペルを間違えた文字列を代入します。
    string s = "Hello Kamba Kan!!";

    // スペルミスを修正します。
    /*
    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16
    H  e  l  l  o     K  a  m  b  a     K  a  n  !  ! 
    
    13文字目が a を u にしてあげる必要があります。
    */

    s[13] = 'u';

    // 修正後の文字列
    cout << s << endl;

    return 0;
    
}