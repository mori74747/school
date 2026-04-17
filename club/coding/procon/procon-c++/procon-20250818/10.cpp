#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;

int main(){
    ull n;
    cin >> n;

    vector<ull> a(n), b(n);
    for (ull i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ull i = 0; i < n; i++) {
        cin >> b[i];
    }

    ull ans = 0;
    for (ull bit = 0; bit < (1 << n); ++bit) {
        ull x = 0, y = 0;
        for (ull i = 0; i < n; ++i) {
            if ((bit & (1 << i)) > 0) {
                x += a[i];
            } else {
                y += b[i];
            }
        }
        if (x == y) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}

//g++ test.cpp; a.out
