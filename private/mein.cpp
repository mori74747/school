#include <iostream>
#include <utility>

using namespace std;

int main(){

    pair<pair<float,float> ,pair<float,float>>data;

    cin >> data.first.first >> data.first.second >> data.second.first >> data.second.second;

    if(data.first.first < data.second.first){
        if(data.first.second < data.second.second){
            cout << data.second.first << " " << data.first.second << "\n";
        }
        else{
            cout << data.second.first << " " << data.second.second << "\n";
        }
    }
    else{
        if(data.first.second < data.second.second){
            cout << data.first.first << " " << data.first.second << "\n";
        }
        else{
            cout << data.first.first << " " << data.second.second << "\n";
        }
    }

    return 0;
}
