#include <iostream>
#include <utility>

using namespace std;

int main(){

    pair<pair<double,double> ,pair<double,double>>data;

    cin >> data.first.first >> data.first.second >> data.second.first >> data.second.second;

    double ans;

    if(data.first.first < data.second.first){
        if(data.first.second < data.second.second){
            printf("%.6lf %.6lf\n",data.second.first,data.first.second);
        }
        else{
            printf("%.6lf %.6lf\n",data.second.first,data.second.second);
        }
    }
    else{
        if(data.first.second < data.second.second){
            printf("%.6lf %.6lf\n",data.first.first,data.first.second);
        }
        else{
            printf("%.6lf %.6lf\n",data.first.first,data.second.second);
        }
    }

    return 0;
}

    