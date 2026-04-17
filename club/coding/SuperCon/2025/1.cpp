#include <stdio.h>
#include <sc1.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <bitset>

# define SC_L 20 // 格子の x および y 軸方向の長さ L
# define SC_SC 100 // ひずみの臨界値 Sc
# define SC_alpha 0.20 // αの値 ((2) 式参照)
# define SC_t 10 // 下にあたえられるひずみの時刻 t
# define SC_A 10.0 // 評価関数 E のパラメータ A

using namespace std;

clock_t SC_starttime,SC_endtime;

int main(){
    int SC_Ne; // 問題の地震の回数 Ne を格納する整数
    int SC_Sf[SC_L+1][SC_L+1]; // 問題の時刻 t でのひずみを格納する 2 次元整数配列
    int SC_S0[SC_L+1][SC_L+1]; // 解答を格納する 2 次元整数配列

    pair<int, int> v[4] = {pair(1, 0), pair(-1, 0), pair(0, 1), pair(0, -1)};

    // SC_input();
    scanf("%d",&SC_Ne);
    for(int i=1; i<= SC_L; i++){
        for(int j=1; j<= SC_L; j++){
            scanf("%d",&SC_Sf[i][j]);
        };
    };
    SC_starttime=clock();

    vector<vector<int>> g_grid(SC_L+1, vector<int>(SC_L+1));
    vector<vector<pair<int, int>>> g_list(SC_SC, vector<pair<int, int>>());
    queue<pair<int, int>> q;

    for (int x = 1; x <= SC_L; x++) {
        for (int y = 1; y <= SC_L; y++) {
            g_grid[x][y] = SC_Sf[x][y];
            g_list[SC_Sf[x][y]].push_back(pair(x, y));
        }
    }

    int i = 0; //現在どのグループが0(直前が震源)だったかを判定
    int num = 0;
    for (int t = SC_t; t >= 0; t--) {
        printf("t:%d\n", t);
        printf("g_list[i].size() == %d\n", g_list[i].size());
        if (g_list[i].size() != 0) num++;
        for (int j = 0; j < g_list[i].size(); j++) {
            q.push(g_list[i][j]);
        }
        while(!q.empty()) {
            pair<int, int> data = q.front();
            int x = data.first;
            int y = data.second;
            int s_a = g_grid[x][y];
            int s_b;
            if (g_grid[x][y] - i >= 0) {
                s_b = g_grid[x][y] - i;
            } else {
                s_b = SC_SC + g_grid[x][y] - i;
            }
            q.pop();
            printf("!%d,%d,%d(%d)", x, y, s_a, s_b);

            //震源のひずみを地震が起こる前に設定
            g_list[i].erase(remove(g_list[i].begin(), g_list[i].end(), pair(x, y)), g_list[i].end());

            s_b = SC_SC - 1;
            if (s_b + i < SC_SC) {
                s_a = s_b + i;
            } else {
                s_a = s_b + i - SC_SC;
            }
            g_list[s_a].push_back(pair(x, y));
            g_grid[x][y] = s_a;

            printf("=>%d(%d)\n", s_a, s_b);

            //上下左右のひずみを地震が起こる前に設定
            for (int j = 0; j < 4; j++) {
                int x2 = x + v[j].first;
                int y2 = y + v[j].second;

                //もしその場所がグリッド内なら
                if (x2 >= 1 && x2 <= SC_L && y2 >= 1 && y2 <= SC_L) {
                    int s2_a = g_grid[x2][y2];
                    int s2_b;
                    if (g_grid[x2][y2] - i >= 0) {
                        s2_b = g_grid[x2][y2] - i;
                    } else {
                        s2_b = SC_SC + g_grid[x2][y2] - i;
                    }
                    printf("!!%d,%d,%d(%d)=>", x2, y2, s2_a, s2_b);
                    if (s2_b != 0) {
                        g_list[s2_a].erase(remove(g_list[s2_a].begin(), g_list[s2_a].end(), pair(x2, y2)), g_list[s2_a].end());

                        int tmp = 0;
                        while (s2_b >= (1 / SC_alpha) * (tmp + 1)) {
                            tmp++;
                            s2_b--;
                        }
                        if (s2_b + i < SC_SC) {
                            s2_a = s2_b + i;
                        } else {
                            s2_a = s2_b + i - SC_SC;
                        }
                        printf("%d(%d)\n", s2_a, s2_b);

                        g_list[s2_a].push_back(pair(x2, y2));
                        g_grid[x2][y2] = s2_a;

                        //もし巻き戻したときに地震が起きていたら
                        if (s2_b <= 0) {
                            printf("Push!!\n");
                            q.push(pair(x2, y2));
                        }
                    }
                } else {
                    printf("!!%d,%d,||(||)=>||(||)\n", x2, y2);
                }
            }
        }
        i++;
    }

    for(int i=1; i<= SC_L; i++){
        for(int j=1; j<= SC_L; j++){
            SC_S0[i][j] = g_grid[i][j];
        };
    };

    // SC_output();
    SC_endtime=clock();

    for(int i=1; i<= SC_L; i++){
        for(int j=1; j<= SC_L; j++){
            printf("%d\n",SC_S0[i][j]);
        };
    };
    printf("# elapsed time (sec) = %f \n", (double) (SC_endtime-SC_starttime)/CLOCKS_PER_SEC);

    printf("%d == %d\n", num, SC_Ne);
}