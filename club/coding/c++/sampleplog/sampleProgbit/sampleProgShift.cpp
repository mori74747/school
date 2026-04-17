#include <iostream>
#include <bitset>

using namespace std;

int main() {
    // シフトする値を決めます。
    int signed_val = -1;

    // シフトする回数を決めます。
    int x = 8;

    // 符号なしの値に変換します。（最上位ビットが 1 なので、とても大きな値になるはずです。）
    unsigned int unsigned_val = (unsigned int) signed_val;

    // 論理シフト
    cout << "unsigned int : " << bitset<32>(unsigned_val) << "\n";
    cout << "Left Logic Shift << " << x << " : " << bitset<32>(unsigned_val << x) << "\n";
    cout << "Right Logic Shift >> " << x << " : " << bitset<32>(unsigned_val >> x) << "\n";

    // 算術シフト
    cout << " int : " << bitset<32>(signed_val) << "\n";
    cout << "Left Shift << " << x << " : "<< bitset<32>(signed_val << x) << "\n";
    cout << "Right Shift >> " << x << " : " << bitset<32>(signed_val >> x) << "\n\n";

    return 0;
}