#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){

    int Q,type;
    cin >> Q;

    stack<string> present;
    for(int i = 0; i < Q; i++){
        cin >> type;
        if(type == 1){
            string tmp;
            cin >> tmp;
            present.push(tmp);

        }else if(type == 2){
            present.pop();

        }else if(type == 3){
            if(present.empty() == 0){
                cout << present.top() << "\n";
            }else{
                cout << "-1\n";
            }

        }
    }
    return 0;
}