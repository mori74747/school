#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;


int main(){

	// *** 入力の高速化 *** //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// *** コード部分 *** //

	// 入力
	int n, x;	cin >> n >> x;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	int l = 1;
	int r = n;
	while(l <= r){
		int m = (r + l) / 2;

		if(x == a[m]){
			cout << m << "\n";
			break;
		}
		if(x > a[m]){
			l = m + 1;
		}
		if(x < a[m]){
			r = m - 1;
		}
	}

	return (0);
}