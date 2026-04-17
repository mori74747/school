#include <bits/stdc++.h>
using namespace std;
int main(){

    string s;   cin >> s;
    stack<char> data; data.push('-');
    for(int i = 0; i < s.size(); i++){
        char a = s[i];

        if(a == '('){ 
            data.push('(');
            continue;
        }
        if(a == '{'){ 
            data.push('{'); 
            continue;
        }
        if(a == '['){ 
            data.push('['); 
            continue;
        }

        if(a == ')'){
            if(data.top() == '('){
                data.pop();
            }else{
                cout << "No" << "\n"; 
                return 0;
            }
        }
        if(a == '}'){
            if(data.top() == '{'){
                data.pop();
            }else{
                cout << "No" << "\n"; 
                return 0;
            }
        }
        if(a == ']'){
            if(data.top() == '['){
                data.pop();
            }else{
                cout << "No" << "\n"; 
                return 0;
            }
        }
    }
    if(data.size() == 1){
        cout << "Yes" << "\n";
    }else{
        cout << "No"  << "\n";
    }   

    return 0;
}