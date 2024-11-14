#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

float doubleRectIntegralMidPt(int,int,float[2],float[2]);

int main(int argc, char const *argv[])
{
    int m = 4;
    int n = 2;

    float xRange[2] = {1,2};
    float yRange[2] = {1,2};


    doubleRectIntegralMidPt(4,2,xRange, yRange);

    

    return 0;
}

float doubleRectIntegralMidPt(int m, int n, float xRange[1], float yRange[1]){
    float Range_Area = (xRange[1] - xRange[0])*(yRange[1] - yRange[0]);
    float change_in_A = (Range_Area)/ (m*n);
    float change_in_X = (xRange[1] - xRange[0])/m;
    float change_in_Y = (yRange[1] - yRange[0])/n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout << "(" << i << "," << j  << ") ";
        }
        cout << endl;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cout  << "(" << (i*change_in_X)- change_in_X/2 + xRange[0] << "," << (j*change_in_Y) - change_in_Y/2 + yRange[0] << ") ";
        }
        cout << endl;
    }

    cout << "range_area: " << Range_Area << endl;
    cout << "Change in area: " << change_in_A << endl;
    cout << "Change in x: " << change_in_X << endl;
    cout << "Change in y: " << change_in_Y << endl;

    return 0;
}

float function(){

}