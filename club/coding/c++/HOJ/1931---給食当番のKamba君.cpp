#include <iostream>
#include <queue>

using namespace std;

int main(){

    int Q;
    cin >> Q;

    int Query[Q][2];
    queue<int> a;

    for(int i = 0; i < Q; i++){

        cin >> Query[i][0] >> Query[i][1];
    }
    for(int i = 0; i < Q; i++){

        if(Query[i][0] == 1){
            a.push(Query[i][1]);
        }
        else if(Query[i][0] == 2){
            for(int j = 0; j < Query[i][1]; j++){
                int x = a.front();
                cout << x << "\n";
                a.pop();
            }
        }
        else if(Query[i][0] == 3){
            for(int j = 0; j < Query[i][1]; j++){
                int y = a.front();
                a.pop();
                a.push(y);
            }
        }
    }
    return 0;
}