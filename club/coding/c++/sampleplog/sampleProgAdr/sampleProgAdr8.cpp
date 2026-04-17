#include <iostream>
#include <set>

using namespace std;

int main() {
    set <int> s;

    for ( int i = 0; i < 10; i++ ) {
        int x;
        cin >> x;

        s.insert ( x );
    }

    for ( int i = 0; i < 10; i++ ) {

        // i が set の中にあるかを探す。
        // find はその要素の位置をイテレータで返します。
        // 見つからなかったら, .end() を返します。
        auto itr = s.find ( i );

        if ( itr == s.end() ) {
            cout << "Not found" << endl;
        } else {
            cout << "Found : " << *itr << endl;
        }

    }

    return 0;
}