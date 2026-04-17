#include <iostream>
using namespace std;

typedef struct {
    int suji;   // メンバ変数：suji
    char moji;  // メンバ変数：moji
} Ascii;

int main() {
    // Ascii型という構造体を使う

    Ascii a;

    a = { 65, 'A' };
    cout << a.suji << " " << a.moji;

    return ( 0 );
}