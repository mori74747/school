#include <iostream>
#include <string>

using namespace std;

int main(){

    string S;
    cin >> S;

    if(S.find("Hello,World!") == 0 && S.size() == 12){
        cout << "AC\n";
    }else {
        cout << "WA\n";
    }

    return 0;
}