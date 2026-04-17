#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> a (5);

    for ( auto& i : a ) {
        cin >> i;
    }

    for ( auto i : a ) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}