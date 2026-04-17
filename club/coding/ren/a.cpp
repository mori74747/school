#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

int main(){

	for(int i = 0; true; i++){
		int n;	cin >> n;
		if(n == 0){
			break;
		}
		vector<int> a(50,10001);
		for(int j = 0; j < n; j++){
			cin >> a[j];
		}
		sort(a.begin(),a.end());

		int ans = 1, ct = 1;
		for(int j = 0; j < n-1; j++){
			if(a[j]+1 == a[j+1]){
				ct++;
			}else{
				ans = max(ans, ct);
				ct = 1;
			}
		}
		if(ct != 1){
			ans = max(ans, ct);
		}
		cout << ans << "\n";
	}
	return (0);
}
