#include <bits/stdc++.h>
#define ll long long
using namespace std;
//segmentTree
struct SegmentTree {
    vector<ll> data;
    int size;

    // 配列の初期値を決めておく
    ll syoki=0;     
    // 1.最小値 2.最大値 3.総和 4.総差 5.最小公倍数 6.最大公約数
    int PP = 1;
    ll f(ll a,ll b,int c){
        if(c == 1)
            return min(a,b);
        if(c == 2)
            return max(a,b);
        if(c == 3)
            return (a + b);
        if(c == 4)
            return (a - b);
        if(c == 5){
            ll x = a * b;
            if(a < b)
                swap(a,b);
            ll r = a % b;
            while (r != 0){
                a = b; b = r;
                r = a % b;
            }
            return (x/b);
        }
        if(c == 6){
            if(a < b)
                swap(a,b);
            ll r = a % b;
            while (r != 0){
                a = b; b = r;
                r = a % b;
            }
            return (b);
        }
        return 0;
    }
    SegmentTree(int n) {
        size = 1;
        while (size < n) {
            size <<= 1;
        }
            data.assign(2 * size, syoki);
    }
    void set(int x){
        for(int i = 0; i < x; i++){
            cin >> data[i];
        }
    }
    ll query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return(syoki);
        }
        if (a <= l && r <= b) {
            return(data[k]);
        }
        return(f(query(a, b, 2 * k + 1, l, (l + r) >> 1), query(a, b, 2 * k + 2, (l + r) >> 1, r),PP));
    }

    ll query(int a, int b) {
        return(query(a, b, 0, 0, size));
    }

    void update(int k, ll x) {
        k += size - 1;
        data[k] = x;
        while (k > 0) {
            k = (k - 1) >> 1;
            data[k] = f(data[2 * k + 1], data[2 * k + 2],PP);
        }
    }
};
//本文
int main(){

    int n,q,A;

    cin >> n;
    SegmentTree ret(n);

    ret.set(n);

    cin >> q;
    for(int i = 0; i < q; i++){
        int pat;    cin >> pat;
        if(pat == 1){
            int pos,x;
            cin >> pos >> x;
            ret.update(pos-1,x);
        }else if(pat == 2){
            int l,r;
            cin >> l >> r;
            cout << ret.query(l-1,r) << "\n";
        }
    }
    return 0;
}