#include <bits/stdc++.h>
#define p pair<int,pair<int,int>>
using namespace std;
int main(){

    int n, m, x, s, g;
    cin >> n >> m >> x >> s >> g;

    // pair(累計時間、頂点、どこの頂点から来たか
    priority_queue<p, vector<p>, greater<p>> uq;
    vector<pair<int,int>> data(n,INT_MAX);
    uq.push(0,s,s);

    int sum = 0;
    for(int i = 0; i < m; i++){
        int u, v, t;
        cin >> u >> v >> t;

        

        if(data[u].second > t ){
            data[u].second = t;
            uq.push(t,v,u);
            
        }
        
    }


    












    return 0;
}