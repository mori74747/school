#include<bits/stdc++.h>
using namespace std;

// long long 型を ll 型に
typedef long long ll;

// SegmentTree
struct SegmentTree {
    vector<ll> data;

    // ここは必ず整数型にしてください。
    // 配列の長さを指定するのに浮動小数点数型は使えません。
    ll size;

    // syoki はセグメントツリーの各要素の初期値を表す。
    // 0 にしておくと、各要素は 0 で初期化される。
    // 問題によって適切な初期値に変更すること。
    ll syoki = 0;

    // 引数や戻り値の型は、オーバーフローしないように気を付けること！
    ll f ( ll a, ll b ){
        // 最大値: max  最小値: min 総和 a+b
        return (  a+b );
    }

    SegmentTree(ll n) {
    size = 1;
    while (size < n) {
        size <<= 1;
    }
        data.assign(2 * size, syoki);
    }

    // 引数の数 5 個の場合の関数
    ll query(ll a, ll b, ll k, ll l, ll r) {
        if (r <= a || b <= l) {
            return(syoki);
        }
        if (a <= l && r <= b) {
            return(data[k]);
        }
        return ( f(query(a, b, 2 * k + 1, l, (l + r) >> 1), query(a, b, 2 * k + 2, (l + r) >> 1, r)) );
    }

    // 引数の数 2 個の場合の関数
    ll query(ll a, ll b) {
        return(query(a, b, 0, 0, size));
    }

    void update(ll k, ll x) {
        k += size - 1;
        data[k] = x;
        while (k > 0) {
            k = (k - 1) >> 1;
            data[k] = f(data[2 * k + 1], data[2 * k + 2]);
        }

        return;
    }
};

int main(){
    int N, Q;
    cin >>N >> Q;
    SegmentTree A(N);
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        A.update(i,a);
    }
    int l,r,p,V;
    for(int i = 0; i < Q; i++){
        cin>>a;
        if(a==1){
            cin >> l >> r;
            l--;
            cout << A.query(l,r)<<"\n";
        }else if(a==2){
            cin >> p >> V;
            p--;
            A.update(p,V);
        }
    }
    return 0;
}
