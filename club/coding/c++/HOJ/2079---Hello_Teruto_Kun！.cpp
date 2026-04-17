#include <bits/stdc++.h>
using namespace std;
int main(){

    int n;  cin >> n;
    string ans = "Hello Teruto Kun!";
    for(int i = 0; i < n; i++){
        char tmp;   cin >> tmp;
        if(tmp == 'U'){
            int x;  cin >> x; x--;
            if('a' <= ans[x] && ans[x] <= 'z')
                ans[x] = ans[x]-32;
        }
        if(tmp == 'L'){
            int x;  cin >> x; x--;
            if('A' <= ans[x] && ans[x] <= 'Z')
                ans[x] = ans[x]+32;
        }
        if(tmp == 'R'){
            int r,l; cin >> r >> l; r--;
            reverse(ans.begin()+r,ans.begin()+l);
        }
        if(tmp == 'A'){
            string s;  cin >> s;
            ans += s;
        }
        if(tmp == 'D'){
            int k;  cin >> k;
            ans.replace(ans.size()-k, k, "");
        }
    }
    cout << ans << "\n";

    return 0;
}