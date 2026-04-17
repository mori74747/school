#include <iostream>
#include <map>

using namespace std;
int main(){

    int N,Q;
    cin >> N >> Q;

    map<int,int> st;

    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        st.insert({tmp,1});
    }
    for(int i = 0; i < Q; i++){
        int tmp;
        cin >> tmp;
        if(st[tmp] == 1){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
    return 0;
}