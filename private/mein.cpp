#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;


int main(){

	// *** 入力の高速化 *** //
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	// *** コード部分 *** //

	int h, w;	cin >> h >> w;

	vector<string> data(h+1);
	for(int i = 1; i <= h; i++){
		data[i].push_back(' ');
		cin >> data[i];
	}

	int ans = 0;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			for(int h1 = 1; h1 <= h; h1++){
				for(int h2 = 1; h2 <= w; h2++){
					for(int w1 = 1; w1 <= h; w1++){
						for(int w2 = 1; w2 <= w; w2++){
							if((h1 <= i && i <= h2) && (w1 <= j && j <= w2)){
								if(data[i][j] == data[h1+h2-i][w1+w2-j]){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";

	return (0);
}