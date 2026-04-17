#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	vector<int> dp(n,INT32_MAX);
	dp[0] = 0;
	
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= k; j++){
			if(i >= j){
				dp[i] = min(dp[i], dp[i-j] + abs(v[i] - v[i-j]));
			}
		}
	}
	
	cout << dp[n-1] << "\n";
}
