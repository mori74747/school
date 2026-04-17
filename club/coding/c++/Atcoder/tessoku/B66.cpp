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

    ll n,m,ct=0;
    cin >> n >> m;

    UnionFind graph(n + 1);

    vector<ll> dataA(m);
    vector<ll> dataB(m);

    vector<ll> A,B;
    for(ll i = 0; i < m; i++){
        cin >> dataA[i] >> dataB[i];
        graph.unite(dataA[i],dataB[i]);
    }
    ll q;  cin >> q;
    for(ll i = 0; i < q; i++){
        int pat; cin >> pat;
        ll u,v,x;
        if(pat == 1){
            cin >> x;
            x--;
            A[ct] = dataA[x];
            B[ct] = dataB[x];

            if(A[ct] > B[ct])
                swap(A[ct],B[ct]);
            ct++;
        }else if(pat == 2){
            cin >> u >> v;
            u--; v--;
            if(u > v)
                swap(u,v);
            int j=0;
            if(graph.find(u) == graph.find(v)){
                for(int i = 0; i < ct; i++){
                    if(A[i] == u && B[i] == v){
                        j++;
                    }
                }
                if(j == 0){
                    cout << "Yes\n";
                }else{
                    cout <<"No\n";
                }         
            }else{
                cout << "No\n";
            }
        }
    }
    return ( 0 );
}