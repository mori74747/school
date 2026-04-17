#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;
int main(){

    int M;
    cin >> M;

    map <char,string> cs;
    queue<char> key;

    char c; string s;
    for(int i = 0; i < M; i++){
        cin >> c >> s;
        cs.insert({c,s});
    }
    int Q;
    cin >> Q;

    string no = cs['-'];

    for(int i = 0; i < Q; i++){
        cin >> s;
        if(s == "IN"){
            cin >> c;
            key.push(c);
        }
        if(s == "OUT"){
            if(key.empty()){
                cout << "0" << endl;
            }else if(cs[key.front()] == no){
                cout << "-1" << "\n";
                key.pop();
            }else{
                cout << cs[key.front()] << "\n";
                key.pop();
            }

        }
    }



    return 0;
}