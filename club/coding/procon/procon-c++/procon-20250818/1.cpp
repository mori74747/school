#include <bits/stdc++.h>
using namespace std;
int main(){

    char K,G;
    cin >> K >> G;

    if(K == 'g'){
        if(G == 'g') cout << "Draw\n";
        if(G == 'c') cout << "Win\n";
        if(G == 'p') cout << "Lose\n";
    }
    if(K == 'c'){
        if(G == 'c') cout << "Draw\n";
        if(G == 'p') cout << "Win\n";
        if(G == 'g') cout << "Lose\n";
    }
    if(K == 'p'){
        if(G == 'p') cout << "Draw\n";
        if(G == 'g') cout << "Win\n";
        if(G == 'c') cout << "Lose\n";
    }




    return 0;
}