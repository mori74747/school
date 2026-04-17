#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){

    int N,Q;
    cin >> N >> Q;

    vector<int> a(N);
    for(auto &i : a){
        cin >> i;
    }
    sort(a.begin(),a.end());
    int x;
    for(int i = 0; i < Q; i++){
        cin >> x;
        int ui = lower_bound(a.begin(),a.end(),x) - a.begin();
        cout << a.size() - ui << "\n";
    }


    return 0;
}