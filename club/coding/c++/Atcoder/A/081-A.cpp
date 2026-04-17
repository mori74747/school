#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){

    int ans=0;
    // vector<char> a(3);
    // for(auto i = a.begin(); i != a.end(); i++){
    //     cin >> *i;
    // }
    // for(auto &i : a){
    //     if(i == '1'){
    //         ans++;
    //     }
    // }
    string s;
    cin >> s;
    for(char c :s){
        if( c == '1')
            ans++;
    }
    cout << ans << "\n";


    return 0;
}