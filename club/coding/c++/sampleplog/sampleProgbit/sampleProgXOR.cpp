#include <iostream>
#include <bitset>   // 2進数を表示するために使用するヘッダーファイル

using namespace std;

int main() {
    // 最初に 0b を付けることで2進数の定数を作ることができます。
    // これを利用して2進数を代入しています。

    // ぜひ値を変えてみて遊んでください。
    int a = 0b1010;
    int b = 0b1101;

    int ans = a ^ b;

    // ここから下は bitset というヘッダーファイルの機能を使って 2進数で表示させます。
    
    // 12 ビットの2進数に変換しています。
    bitset <12> ansBit ( ans );
    cout << ansBit << endl;

    return 0;
}