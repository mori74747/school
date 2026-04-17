#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

long long kamba (long long n,long long k){
    if(k == 0 || n == k){
        return (1);
    }
    return ( kamba(n-1,k-1) + kamba(n-1,k) );
}

int main(){

    int n;
    cin >> n;

    for(int k = 0; k <= n; k++){
        cout << kamba(n,k);
        if(k == n){
            cout << endl;
        }else{
            cout << " ";
        }
    }


    return 0;
}

//   5!   5 + (5-1) + (5-2)