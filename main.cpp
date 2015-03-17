#include<cstdlib>
#include<iostream>

#include "src/Calculate.h"

using namespace std;

int main() {
    string input;

    cin >> input;
    Calculate calculate(input);
    if (calculate.isError()) {
        cout<< "Error!"<<endl;
    } else {
        cout<<calculate.getAnswer()<<endl;
    }

}