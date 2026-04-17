#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        int maxi = 0; int count = 0;
        int temp = 1;

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                maxi += v[j]; 
                count++;
            }
        }
        if(maxi <= x){
            ans = max(ans, count);
        }

    }
    cout << ans << "\n";

    return 0;
}