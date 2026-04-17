#include <bits/stdc++.h>
using namespace std;
int main(){

    long long n,w;
    cin >> n >> w;

    vector<long long> data(w+1,0);

    vector<pair<long,long>> dp(n+1);
    dp[0].first = 0; dp[0].second = 0;

    for(int i = 1; i <= n; i++){
        cin >> dp[i].first >> dp[i].second;
    }
    for(int i = 1; i <= n; i++){
        for(int j = w; j >= 1; j--){
            if(j >= dp[i].first){
                data[j] = max(data[j],data[j-dp[i].first] + dp[i].second);
            }
        }
    }
    cout << data[w] << "\n";

    return 0;
}