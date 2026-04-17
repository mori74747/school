#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;   cin >> s;

    int n;  cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        char tmp;   cin >> tmp;
        if(s.find(tmp) != -1){
            ans++;
            break;
        }
    }
    if(ans == 0){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

}