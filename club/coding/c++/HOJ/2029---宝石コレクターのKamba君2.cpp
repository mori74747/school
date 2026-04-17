#include <iostream>
#include <map>

using namespace std;

int main(){

    int N,Q,tmp,B;
    cin >> N;

    map<int,int> A;

    for(int i = 0; i < N; i++){
        cin >> tmp;
        A.insert({tmp,0});
        A[tmp]++;
    }
    cin >> Q ;
    for(int i = 0; i < Q; i++){
        cin >> B;
        cout << A[B] << "\n";
    }
    
    return 0;
}