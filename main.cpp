#include<cstdlib>
#include<iostream>

#include "src/Calculate.h"

using namespace std;

int main() {
    string input;

    cin >> input;
    Calculate calculate(input);
    calculate.work();

}