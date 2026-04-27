#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;


int main(){

	// *** 入力の高速化 *** //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// *** コード部分 *** //

	int n, k;	cin >> n >> k;
	
	vector<int> data(n+1);
	for(int i = 0; i < n; i++){
		cin >> data[i];
	}
	sort(data.rbegin(),data.rend());

	int i = 0;
	for(int j = 0; (j < k)&&(i < n); j++){
		int tmp = data[i];
		data[i] = 0;
		while(tmp == data[i+1]){
			data[i+1] = 0;
			i++;
		}
		i++;
	}

	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans += data[i];
	}

	cout << ans << "\n";

	return (0);
}