//
// Created by xiaowei on 2015/3/15.
//

#include "Calculate.h"
#include "Suffix.h"
#include "Check.h"

#include<stack>
#include<string>
#include<iostream>

using namespace std;

int Calculate::calculate(char opera, int a, int b) {
    int result = 0;

    switch (opera) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    return result;
}


Calculate::Calculate(string s) {
    infix = s + '#';
}

void Calculate::setExpression(string s) {
    infix = s + '#';
}

int Calculate::getAnswer() {
    stack<int> numberStack;

    Suffix suffix(infix);
    vector<Cell> suffixExpression = suffix.getSuffix();

    for (int i = 0; i < suffixExpression.size() ; i++) {
        if (suffixExpression[i].isNumber())
            numberStack.push(suffixExpression[i].number);
        else {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            numberStack.push(calculate(suffixExpression[i].opt, a, b));
        }
    }

    return numberStack.top();
}

bool Calculate::isError() {
    Check check(infix);
    return  !check.checkError();
}

string Calculate::getSuffix() {
    Suffix suffix(infix);
    vector<Cell> suffixExpression = suffix.getSuffix();

    string suffixString;
    for (int i = 0; i < suffixExpression.size() ; i++) {
       if (suffixExpression[i].isNumber()) {
           suffixString += to_string(suffixExpression[i].number);
       }
       else {
           suffixString += suffixExpression[i].opt;
       }
       if (i != (suffixExpression.size()-1)) {
           suffixString += " ";
       }
    }
    return suffixString;
}