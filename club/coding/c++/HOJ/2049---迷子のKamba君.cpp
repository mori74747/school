#include <bits/stdc++.h>
using namespace std;
int main(){

    int n,m;
    cin >> n >> m;

    int ans = 0;

    set <pair<int,int>> xy;
    for(int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        if(x > y){
            swap(x,y);
        }
        if(x == y){
            ans++;
        }else{
            int size = xy.size();
            xy.insert({ x, y });
            if(size == xy.size()){
                ans++;
            }
        }

        
    }

    cout << ans << "\n";

    return 0;
}
