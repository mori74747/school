#include <iostream>
#include <vector>

using namespace std;

int main(){

    int M, N;
    cin >> M >> N;

    char C[N];
    vector<vector<int>> data(M,vector<int> (N));

    for(int i = 0; i < N; i++){
        cin >> C[i];
    }
    vector<int> total(N);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            cin >> data[i][j];

            total[j] += data[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        int ans = total[i] / M;

        cout << C[i]<< " ";
        cout << ans << "\n";
    }


    return 0;
}