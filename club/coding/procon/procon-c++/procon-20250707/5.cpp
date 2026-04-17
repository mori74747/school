#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    int N,X,total=0;
    cin >> N >> X;

    vector<int> V(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    sort(V.begin(), V.end());
    
    for(int i = 0; i <= N; i++){
        if(X >= total && i != N){
            total += V[i];
        }else if(X >= total && i == N){
            cout << i << "\n";
            break;
        }else{
            cout << i-1 << "\n";
            break;
        }
    }
    return 0;
}