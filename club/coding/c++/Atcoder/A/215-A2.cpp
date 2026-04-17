#include <iostream>
#include <string>

using namespace std;

int main(){

    string S;
    cin >> S;

    if( "Hello,World!" == S ){
        cout << "AC\n";
    }else {
        cout << "WA\n";
    }

    return 0;
}