#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    int Q, t, a;
    char c; int x;
    cin >> Q;

    stack<char> data;
    vector<int> ans(200);

    for(int i = 0; i < Q; i++){
        cin >> t;
        if(t == 1){

            cin >> c;
            data.push(c);
        }
        else if(t == 2){

            cin >> x;
            for(int j = 0; j < x; j++){

                a = data.top();" "
                data.pop();
                ans[a]++;
            }
        }
        else if(t == 3){

            cin >> x;
            for(int j = 0; j < x; j++){
                data.pop();
            }
        }
    }
    for(int i = 1; i <= 4; i++){
        for(int j = 'A'; j <= 'Z'; j++){
            if( j == 'S' && i == 1){
                cout << ans[j] << " ";
            }
            else if( j == 'K' && i == 2){
                cout << ans[j] << " ";
            }
            else if( j == 'R' && i == 3){
                cout << ans[j] << " ";
            }
            else if( j == 'E' && i == 4){
                cout << ans[j] << "\n";
            }
        }
    }

    return 0;
}