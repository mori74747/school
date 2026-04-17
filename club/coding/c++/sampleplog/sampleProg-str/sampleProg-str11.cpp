#include <iostream>
#include <string>

using namespace std;

int main(){

    string t,s;

    cout << " s = ";
    cin >> s;

    cout << "\n t = ";
    cin >> t;
    cout << "\n";
/*
    s = "*";

    t = ":";
    
*/
    if(s > t){
        cout << s << " のほうが大きい\n";
    }else if(t > s){
        cout << t << " のほうが大きい\n";
    }else{
        cout << "どっちも同じ\n";
    }
    
    return 0;
}
