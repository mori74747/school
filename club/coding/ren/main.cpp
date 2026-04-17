#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){


	for(ll i = 0; true; i++){

		ll n, m;		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<ll> a(n); 
		for(ll j = 0; j < n; j++){
			cin >> a[j];
		}
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());

		ll k = 0, ans = 0;
		for(ll j = 1; j <= m; j++){
			if((j == a[k])||(j % 7 == 6)||(j % 7 == 0)){
				if(j == a[k]){
					k++;
				}
			}else{
				ans++;
			}
		}
		cout << ans << "\n";

	}

	return (0);
}
