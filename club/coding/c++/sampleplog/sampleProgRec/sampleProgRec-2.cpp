// 末尾再起で二の累乗を実装

#include <iostream>
using namespace std;

long long powerOfTwo ( int x, int ans ) {
    
    if ( x == 0 ) {
        return ( ans );
    } else {
        return powerOfTwo ( x - 1, ans * 2 );
    }

}

int main () {
    int x;
    cin >> x;

    cout << powerOfTwo ( x, 1 ) << endl;
    
    return ( 0 );
}