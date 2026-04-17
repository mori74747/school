#include <iostream>
#include <vector>

using namespace std;

// long long を ll 型に
typedef long long ll;

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

    return ( 0 );
}