#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>

#include <string>
using std::string;

#include <sstream>

#include <vector>
using std::vector;

#include <ctype.h>
using std::isdigit;

float doubleRectIntegralMidPt(int,int,float[2],float[2]);

float executeFunction(string function){

    int paranthBoth = function.find(")(");
    int paranthOpen = function.find("(");
    int paranthClosed = function.find(")");


    if(paranthClosed != paranthOpen){
        string endingOperation = ""; 

        int subFuncSize = paranthClosed-paranthOpen;
        string subFunc = function.substr(paranthOpen+1,subFuncSize-1);

        if(paranthBoth == paranthClosed){
            endingOperation = "*";
        }

        int subFuncValue = executeFunction(subFunc);
        function.replace(paranthOpen, subFuncSize+1, std::to_string(subFuncValue)+ endingOperation);

        return executeFunction(function);

    }
    else{

        vector<char> operations;
        vector<int> numbers;

        // Gets our operations '+', '-', '/', etc
        for(char& c: function){
            if(!isdigit(c)){
                operations.push_back(c);
                c = ' ';
            }
        }

        // Gets our numbers 234, 12, 536
        int temp = 0;
        std::stringstream ss(function);
        while(ss){
            ss >> temp;
            if(ss){numbers.push_back(temp);}
        }

        // Multiplication and Division
        vector<char>::iterator opStart = operations.begin();
        vector<char>::iterator opEnd = operations.end();
        int index = 0;
        while(opStart!=opEnd){
            if(*(opStart) == '*'){
                int num1 = numbers.at(index);
                int num2 = numbers.at(index+1);

                operations.erase(opStart);
                numbers.erase(numbers.begin() + index+1);

                numbers.at(index) = num1*num2;
                index--;

            }
            else if(*(opStart) == '/'){
                int num1 = numbers.at(index);
                int num2 = numbers.at(index+1);

                operations.erase(opStart);
                numbers.erase(numbers.begin() + index+1);

                numbers.at(index) = num1/num2;
                index--;
            }

            opStart++;
            index++;
        }

        // Addition/Subtraction
        opStart = operations.begin();
        opEnd = operations.end();
        index = 0;
        while(opStart!=opEnd){
            if(*(opStart) == '+'){
                int num1 = numbers.at(index);
                int num2 = numbers.at(index+1);

                operations.erase(opStart);
                numbers.erase(numbers.begin() + index+1);

                numbers.at(index) = num1+num2;
                index--;
            }
            else if(*(opStart) == '-'){
                int num1 = numbers.at(index);
                int num2 = numbers.at(index+1);

                operations.erase(opStart);
                numbers.erase(numbers.begin() + index+1);

                numbers.at(index) = num1-num2;
                index--;
            }

            opStart++;
            index++;
        }

        return numbers.at(0);
    }
}
    
string insertMath(string function, float x, float y){
    int xindex = 0;
    int yindex = 0;

    while(xindex = function.find('x') <= 0){
    }

}

int main(int argc, char const *argv[])
{
    int m = 4;
    int n = 2;

    float xRange[2] = {1,2};
    float yRange[2] = {1,2};

    doubleRectIntegralMidPt(4,2,xRange, yRange);

   string func = "(5+6)(35*8+2)(1+8)";

   cout << executeFunction(func);




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

