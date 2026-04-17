#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(){

    string S,s;
    cin >> S;
    s = S;
    reverse ( S.begin(), S.end () );

    if(s == S){
        cout << "Yes\n";
    }else{
        cout << S << "\n";
    }


    return 0;
}