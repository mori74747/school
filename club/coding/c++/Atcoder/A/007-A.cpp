#include <bits/stdc++.h>
using namespace std;
vector<int> tmp(4);
void check(string k){
    for(int i = 0; i < 4; i++){
        if(k[i] == '#'){
            tmp[i] = 0;
        }else if(k[i] == '.'){
            tmp[i] = 1;
        }
    }
}
int main(){

    int r,c;
    cin >> r >> c;
    int sy,sx,gy,gx;
    cin >> sy >> sx >> gy >> gx;

    vector<vector<char>> data (r,vector<char>(c));
    vector<vector<int>> ans (r,vector<int>(c));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> data[i][j];
        }
    }
    for(int i = 1; i < r - 1; i++){
        for(int j = 1; j < c - 1; j++){
            int ansY = abs(sy - i - 1) ; 
            int ansX = abs(sx - j - 1) ;
            //check(左、右、下、上)
            string temp1 (1,data[i][j-1]);
            string temp2 (1,data[i][j+1]);
            string temp3 (1,data[i-1][j]);
            string temp4 (1,data[i+1][j]);
            string temp = temp1 + temp2 + temp3 + temp4;

            check(temp);

            if(tmp[0] == 1 && ans[i][j-1] == 0)
                ans[i][j-1] = ansY + ansX;
            if(tmp[1] == 1 && ans[i][j+1] == 0)
                ans[i][j+1] = ansY + ansX;
            if(tmp[2] == 1 && ans[i-1][j] == 0)
                ans[i-1][j] = ansY + ansX;
            if(tmp[3] == 1 && ans[i+1][j] == 0)
                ans[i+1][j] = ansY + ansX;
        }
    }
    cout << ans[gy][gx] << endl;






    return 0;
}