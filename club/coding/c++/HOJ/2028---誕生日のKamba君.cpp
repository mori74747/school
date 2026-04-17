#include <bits/stdc++.h>
using namespace std;

int kamba (int m, int d){
    int ans;
    if( m == 7 && d == 4){
        ans = 1;
    }else{
        ans = 0;
    }
    return (ans);
}
int main(){

    int m, d;
    cin >> m >> d;

    if(kamba(m, d)){
        cout << "Happy Birthday!\n";
    }
    return 0;
}