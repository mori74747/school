#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;  cin >> n;
    long long total = 0;
    for(int i = 0; i < n; i++){
        int tmp;    cin >> tmp;
        total += tmp;
    }
    if(total == 0){
        cout << "Unknown\n";
    }else if(total > 0){
        cout << "Positive\n";
    }else{
        cout << "Negative\n";
    }

    return 0;
}