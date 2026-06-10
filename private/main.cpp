#include <iostream>
#include <utility>

using namespace std;

int main(){

    pair<double,double> data1, data2;

    cin >> data1.first >> data1.second;
    cin >> data2.first >> data2.second;
    printf("%.6lf " , max(data1.first , data2.first));
    printf("%.6lf\n", min(data1.second, data2.second));

    return 0;
}
