#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 2次元配列の解法
// 1次元配列の解法を下にあります。
/*

int main () {
    int n, s;
    cin >> n >> s;

    // DPテーブルの用意
    vector < vector < bool > > dp ( n + 1, vector < bool > ( s + 1 ) );

    // カードの用意
    vector <int> card ( n + 1 );

    card[0] = 0;

    for ( int i = 1; i <= n; i++ ) {
        cin >> card[i];
    }

    // 初期化
    dp[0][0] = true;

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j <= s; j++ ) {
            if ( dp[i][j] == true ) {
                // そのまま下におろす遷移
                dp[i + 1][j] = true;
                
                // カードを使った場合の遷移
                int sum = j + card[i + 1];

                // dpテーブルの配列外に出ないように判定する。
                if ( sum <= s ) {
                    dp[i + 1][sum] = true;
                }
            }
        }
    }

    if ( dp[n][s] == true ) {
        cout << "Win" << endl;
    } else {
        cout << "Lose" << endl;
    }

    return 0;
}

*/
// 1次元配列の解法（こちらを覚えるとよい）
int main () {
    int n, s;
    cin >> n >> s;

    // DPテーブルを用意する。
    vector <bool> dp ( s + 1 );

    // カードを用意する。
    vector <int> card ( n + 1 );
    card[0] = 0;

    for ( int i = 1; i <= n; i++ ) {
        cin >> card[i];
    }

    // dp の初期化をする。
    dp[0] = true;

    // 後ろから見ていかないと、本当は変えるべきでない場所を変えてしまう場合がある！
    // 例えば、入出力例 1 だと、 カード 1 まで見るとき、 0 と 2 だけが true ですが...
    // 前から見てしまうと, 0, 2, 4, 6 が true になってしまう可能性が高いです。
    // 何か工夫をすればそうはなりませんが、普通は後ろから見て対策します。

    for ( int i = 1; i <= n; i++ ) {
        for ( int j = s; j >= 0; j-- ) {
        
            if ( dp[j] == true ) {
                int sum = j + card[i];

                // 配列外参照しないようにする！
                if ( sum <= s ) {
                    dp[sum] = true;
                }
            }
        
        }
    }

    if ( dp[s] == true ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;

}
