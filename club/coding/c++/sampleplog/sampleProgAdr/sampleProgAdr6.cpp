#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int> a (5);

    for ( auto i = a.begin(); i != a.end(); i++ ) {
        cin >> *i;
    }

    for ( auto i = a.begin(); i != a.end(); i++ ) {
        cout << *i << " ";
    }

    cout << endl;
    
    for ( auto i = a.rbegin(); i != a.rend(); i++ ) {
        cout << *i << " ";
    }

    cout << endl;

    return 0;
}