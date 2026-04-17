#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tako (ll a, ll b, ll x){
    ll ans = (a + b) * (x - a);
    return (ans);
}
int main(){

    ll  a,b,x;
    cin >> a >> b >> x;

    cout << tako(a,b,x) << "\n";


    return 0;
}