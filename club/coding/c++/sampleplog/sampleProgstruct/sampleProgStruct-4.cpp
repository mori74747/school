#include <iostream>
using namespace std;

typedef struct {
    int first;
    char second;
} Pair;

int main() {
    // pair <int, char> を疑似再現
    Pair a;

    a = { 65, 'A' };
    cout << a.first << " " << a.second;

    return ( 0 );
}