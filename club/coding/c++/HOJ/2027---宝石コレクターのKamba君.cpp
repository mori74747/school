#include <iostream>
#include <set>

using namespace std;

int main(){

    int N,M;
    long long temp;
    set<int> ans;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> M;
        for(int j = 0; j < M; j++){
            cin >> temp;
            ans.insert(temp);
        }
    }
    cout << ans.size() << "\n";

    return 0;
}