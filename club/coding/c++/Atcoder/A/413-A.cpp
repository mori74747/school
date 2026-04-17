#include <iostream>
#include <vector>
using namespace std;
int main(){

    int n,m;    int ans = 0;
    cin >> n;
    cin >> m;

    vector<int> a(n);
    for(int &i : a){
        cin >> i;
        ans += i;
    }
    if(ans <= m){
        cout << "Yes\n";
    }else{
        cout <<"No\n";
    }

    return 0;
}