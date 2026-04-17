#include <iostream>
#include <string>

using namespace std;

int main(){

    int ans = 0;
    string C1,C2;
    cin >> C1 >> C2;

    for(int i = 0; i < C1.size; i++){
        if(C1[i] == C2[2 - i]){
            ans++;
        }
    }
    if(ans == C1.size()){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}