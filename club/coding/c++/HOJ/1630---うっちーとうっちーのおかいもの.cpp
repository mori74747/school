#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){

    int n;
    ull m;
    cin >> n >> m;

    vector<vector<int>> cv (n,vector<int>(2));
    for(int i = 0; i < n; i++){
        cin >> cv[i][0] >> cv[i][1];
    }

    long long ValueAns = 0;
    for(int i = 0; i < (1 << n); i++){
        ull maxi = 0;
        long long value = 0;

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                maxi += cv[j][0]; 
                value += cv[j][1];
            }
        }
        if(maxi <= m){
            ValueAns = max(ValueAns, value);
        }

    }
    cout << ValueAns << "\n";

    return 0;
}