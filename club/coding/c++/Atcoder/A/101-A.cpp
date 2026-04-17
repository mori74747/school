#include <iostream>
#include <string>

using namespace std;

int main(){

    string S;
    cin >> S;

    int ans = 0;
    for(int i = 0; i < S.size(); i++){

        if(S[i] == '+'){
            ans++;
        }
        else if(S[i] == '-'){
            ans--;
        }
    }
    cout << ans << "\n";



    return 0;
}