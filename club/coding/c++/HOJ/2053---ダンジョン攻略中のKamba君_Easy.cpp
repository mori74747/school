#include <bits/stdc++.h>
using namespace std;
int main(){

    vector<int> A(5,INT32_MAX), B(5,INT32_MAX);

    for(int i = 1; i < 5; i++)
        cin >> A[i];
    for(int i = 2; i < 5; i++)
        cin >> B[i];
    
    vector<int> dp(5,INT32_MAX);
    dp[0] = 0;

    for(int i = 1; i < 5; i++){
        if(i - 1 >= 0)
            dp[i] = min(dp[i] , dp[i - 1] + A[i]);
        if(i - 2 >= 0)
            dp[i] = min(dp[i] , dp[i - 2] + B[i]);
    }
    cout << dp[4] << "\n";

    return 0;
}