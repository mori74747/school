#include <iostream>
using namespace std;

struct pairIC {
    int suji;   // メンバ変数：suji
    char moji;  // メンバ変数：moji
};

int main() {
    // pairIC という構造体を使う
    typedef pairIC Ascii;

    Ascii a;

    a = { 65, 'A' };
    cout << a.suji << " " << a.moji;

    return ( 0 );
}