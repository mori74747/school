#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);  // (P[i], A[i])
    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }

    // dp[i][j] := 左から i 個、右から j 個取ったときの最大スコア
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i + j > n) continue;
            int idx = i + j;

            // 左を取る
            if (i < n) {
                int tmp = i;
                int score = 0;
                if (data[tmp].first - 1 >= i && data[tmp].first - 1 < n - j) {
                    score = data[tmp].second;
                }
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + score);
                ans = max(ans, dp[i + 1][j]);
            }

            // 右を取る
            if (j < n) {
                int tmp = n - j - 1;
                int score = 0;
                if (data[tmp].first - 1 >= i && data[tmp].first - 1 < n - j) {
                    score = data[tmp].second;
                }
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + score);
                ans = max(ans, dp[i][j + 1]);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
