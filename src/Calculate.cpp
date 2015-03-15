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

void Calculate::inspirit(string s) {
    infix = s + '#';
}


void Calculate::pri() {
    cout << infix << endl;
}

int Calculate::getValue() {
    stack<int> numberStack;

    Suffix suffix(infix);
    string suffixExpression = suffix.change();
    for (int i = 0; suffixExpression[i] != '#'; i++) {
        if (Util::checkNum(suffixExpression[i]))
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

void Calculate::work() {
    Check check(infix);

    if (check.checkError()) {
        cout << getValue() << endl;
    }
    else
        cout << "error" << endl;
}


