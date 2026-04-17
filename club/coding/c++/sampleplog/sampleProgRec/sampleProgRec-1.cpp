// 通常再起で二の累乗を実装

#include <iostream>
using namespace std;

long long powerOfTwo ( int x ) {
    
    if ( x == 0 ) {
        return ( 1 );
    } else {
        return ( 2 * powerOfTwo ( x - 1 ) );
    }

}

int main () {
    int x;
    cin >> x;

    cout << powerOfTwo ( x ) << endl;
    
    return ( 0 );
}
