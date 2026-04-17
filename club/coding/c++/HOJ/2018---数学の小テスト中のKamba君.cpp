#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int X,Y;
    cin >> X >> Y;

    if(X < Y){
        if(abs(X) < abs(Y)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    else if(X > Y){
        if(abs(X) > abs(Y)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    else{
        cout << "No\n";
    }



    return 0;
}