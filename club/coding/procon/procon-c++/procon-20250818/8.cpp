#include <bits/stdc++.h>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    pair<int, int> spos, gpos;
    vector<vector<bool>> walls(h, vector<bool>(w, false));
    vector<vector<int>> went(h, vector<int>(w, 0));
    for (int y = 0; y < h; y++) {
        string s;
        cin >> s;
        for (int x = 0; x < w; x++) {
            if (s[x] == 'S') spos = {y, x};
            if (s[x] == 'G') gpos = {y, x};
            if (s[x] == '!') walls[y][x] = true;
        }
    }

    vector<pair<int, int>> v = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    queue<pair<int, int>> q;
    q.push(spos);

    while (q.front() != gpos) {
        pair<int, int> data = q.front();
        q.pop();
        for (int i = 0; i < v.size(); i++) {
            pair<int, int> pos = {data.first+v[i].first, data.second+v[i].second};
            if (pos.first >= 0 && pos.first < h && pos.second >= 0 && pos.second < w)
            if (!walls[pos.first][pos.second] && went[pos.first][pos.second] == 0) {
                went[pos.first][pos.second] = went[data.first][data.second] + 1;
                q.push(pos);
            }
        }
    }
    pair<int, int> data = q.front();
    cout << went[data.first][data.second] << endl;

    return 0;
}

//g++ test.cpp; a.out
