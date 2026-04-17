#include <iostream>
#include <algorithm>

using namespace std;
int main(){

    int N;
    cin >> N;
    
    long long nowTime=0,sum=0;
    long long a,b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;

        nowTime = max(nowTime,a);
        sum += (nowTime - a);
        nowTime += b;

    }
    cout << nowTime / N << "\n";

    return 0;
}
