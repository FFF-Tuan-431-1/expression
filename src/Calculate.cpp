//
// Created by xiaowei on 2015/3/15.
//

#include "Calculate.h"
#include "Util.h"
#include "Suffix.h"
#include "Check.h"

#include<stack>
#include<string>
#include<iostream>

using namespace std;

int Calculate::charToInt(char ch) {
    int num;
    num = (int) (ch - '0');
    return num;
}

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
    string suffixExpression = suffix.getSuffix();
    for (int i = 0; suffixExpression[i] != '#'; i++) {
        if (Util::isNumber(suffixExpression[i]))
            numberStack.push(charToInt(suffixExpression[i]));
        else {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            numberStack.push(calculate(suffixExpression[i], a, b));
        }
    }

    return numberStack.top();
}

bool Calculate::isError() {
    Check check(infix);
    return  !check.checkError();
}

