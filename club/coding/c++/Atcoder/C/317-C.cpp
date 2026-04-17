#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // グラフ情報：重み付き隣接行列
    vector<vector<int>> graph(N, vector<int>(N, -1)); // -1: 道がない

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A--; B--; // 0-indexed
        graph[A][B] = C;
        graph[B][A] = C; // 双方向
    }

    int maxLength = 0;

    for (int i = 0; i < N; i++) {
        stack<vector<int>> stk;

        vector<int> init(N + 2, 0); 
        init[0] = i;
        init[1] = 0;
        init[i + 2] = 1;
        stk.push(init);

        while (!stk.empty()) {
            vector<int> state = stk.top();
            stk.pop();

            int x = state[0];
            int y = state[1];
            maxLength = max(maxLength, y);

            for (int i = 0; i < N; i++) {
                if (graph[x][i] != -1 && state[i + 2] == 0) {
                    vector<int> data = state;
                    data[0] = i;
                    data[1] = y + graph[x][i];
                    data[i + 2] = 1;
                    stk.push(data);
                }
            }
        }
    }

    cout << maxLength << endl;
    return 0;
}