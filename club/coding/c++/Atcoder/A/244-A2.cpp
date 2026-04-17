#include <iostream>
#include <string>

using namespace std;

int main(){

    string N,S;

    cin >> N >> S;

    cout << S.substr( S.length()-1, 1 ) << "\n";

    return 0;
}