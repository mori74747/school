#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;   cin >> s;
    long long n = stoll(s);

    if( n % 7 == 0 || n % 4 == 0 || s.find('7') != -1 || s.find('4') != -1){
        cout << "Yes\n";
    }else {
        cout << "No\n";
    }
}