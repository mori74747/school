#include <bits/stdc++.h>
using namespace std;
int main(){

    int m,n;
    cin >> m >> n;

    vector<long long> data(m+1,0);

    vector<pair<long,long>> dp(n+1);
    dp[0].first = 0; dp[0].second = 0;

    for(int i = 1; i <= n; i++){
        cin >> dp[i].first >> dp[i].second;
    }
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            if(j >= dp[i].first){
                data[j] = max(data[j],data[j-dp[i].first] + dp[i].second);
            }
        }
    }
    cout << data[m] << "\n";

    return 0;
}