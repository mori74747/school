#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, count = 0;
    cin >> N;

    vector<vector<char>> ST (2,vector<char>(N+1));

    for(int i = 0; i < N; i++){
        cin >> ST[0][i];
    }
    for(int i = 0; i < N; i++){
        cin >> ST[1][i];
    }
    for(int i = 0; i < N; i++){
        char x = ST[0][i], y = ST[1][i];

        if( x == y || x == 'l' && y == '1' || x == '1' && y == 'l' || x == '0' && y == 'o' || x == 'o' && y == '0'){
            count++;
        }
    }
    if(count == N){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}
