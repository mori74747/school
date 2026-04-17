#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,x;
    cin >> n >> x;

    vector<int> data(x+1,0);

    vector<pair<int,int>> vs(n+1);
    vs[0].first = 0; vs[0].second = 0;

    for(int i = 1; i <= n; i++){
        cin >> vs[i].first >> vs[i].second;
    }
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= 1; j--){
            if(j >= vs[i].first){
                data[j] = max(data[j],data[j-vs[i].first] + vs[i].second);
            }
        }
    }
    cout << data[x] << "\n";

    return 0;
}