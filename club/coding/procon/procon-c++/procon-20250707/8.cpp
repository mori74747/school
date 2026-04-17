#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

    int N,ans=0;
    cin >> N;

    vector<string> s;
    string temp;
    map<string,int> st;
    for(int i = 0; i < N; i++){

        cin >> temp;
        s.push_back(temp);
    }
    sort(s.begin(),s.end());
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> temp;
        st.insert({temp,1});
    }
    for(int i = 0; i < s.size(); i++){

        if(st[s[i]] != 1){
            cout << s[i] << "\n";
        }
    }


    return 0;
}