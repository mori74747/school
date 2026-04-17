#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

void castle (int n){
    if(n == 1){
        cout << "*" << endl;
    }else{
        castle (n - 1);
        for(int i = 0; i < n; i++){
            cout << "*";
        }
        cout << endl;
        castle (n - 1);
    }
}

int main(){

    int N;
    cin >> N;

    castle(N);

    return 0;
}
