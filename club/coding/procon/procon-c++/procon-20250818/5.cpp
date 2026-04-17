#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;   cin >> s;

    int ans = 0;    int tmp = 0;
    if(s.find('k') != -1){
        for(int i = s.find('k'); i < s.length(); i++){
            if(s.at(i) == 'a'){
                tmp = i;
            }
        }
    }
    if(tmp != 0){
        for(int i = s.find('k'); i <= tmp; i++){
            cout << s.at(i);
        }
        cout << "\n";
    }else{
        cout << "-1\n";
    }


}