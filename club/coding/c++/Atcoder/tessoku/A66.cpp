#include <iostream>
#include <vector>
#define ll long long

using namespace std;

// long long を ll 型に

// UnionFindTree
struct UnionFind
{
    vector< ll > data;
    UnionFind(ll sz)
    {
        data.assign(sz, -1);
    }
    void unite(ll x, ll y)
    {
        x = find(x), y = find(y);
        if(x != y) {
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        }
    }
    ll find(ll k)
    {
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }
    ll size(ll k)
    {
        return(-data[find(k)]);
    }
};

// main 関数
int main () {

    int n,q;
    cin >> n >> q;

    UnionFind graph(n);
    for(int i = 0; i < q; i++){
        int pat; cin >> pat;
        int u,v;
        cin >> u >> v;
        u--;v--;
        if(pat == 1){
            graph.unite(u,v);

        }else if(pat == 2){
            if(graph.find(u) == graph.find(v)){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
    }
    return ( 0 );
}