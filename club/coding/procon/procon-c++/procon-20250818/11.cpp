#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct UnionFind {
    vector<T> data;
    UnionFind(T sz)
    {
        data.assign(sz, -1);
    }
    void unite(T x, T y)
    {
        x = find(x), y = find(y);
        if(x != y) {
            if(data[x] > data[y]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
    }
    T find(T k)
    {
        if(data[k] < 0) return(k);
        return(data[k] = find(data[k]));
    }
    T size(T k)
    {
        return(-data[find(k)]);
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    UnionFind<int> uni(n);
    int maxl = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        uni.unite(a, b);
        maxl = max(maxl, uni.size(a));
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (uni.size(i) == maxl) ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << endl;
    }

    return 0;
}

//g++ test.cpp; a.out
