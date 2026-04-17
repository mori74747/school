#include <iostream>
using namespace std;
int main(){

    int X,Y,Z;
    cin >> X >> Y;

    Z = X - Y;
    if(Z < 0){
        Z *= -1;
    }

    cout << Z << "\n";


    return 0;
}