#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<char> S(2 * N);
    for(int i = 0; i < 2 * N; i++){
        cin >> S[i];
        S[i + 1] = S[i];
        i++;
    }
    for(int i = 0; i < 2 * N; i++){

        cout << S[i];
    }
    cout << "\n";

    return 0;
}