//
// Created by xiaowei on 2015/3/15.
//

#include "Suffix.h"
#include "Util.h"

#include<stack>
#include<string>

using namespace std;

bool Suffix::checkStack(char ch, stack<char> tempStack) {
    if (tempStack.empty() == true || checkPriority(ch, tempStack.top()) == true)
        return true;
    else
        return false;
}

bool Suffix::checkPriority(char one, char two) {
    if (getPriority(one) > getPriority(two))
        return true;
    else
        return false;
}


int Suffix::getPriority(char temp) {
    int priority = 0;
    switch (temp) {
        case '+' :
            priority = 1;
            break;
        case '-' :
            priority = 1;
            break;
        case '*' :
            priority = 2;
            break;
        case '/' :
            priority = 2;
            break;
        case '(' :
            priority = 3;
            break;
        case ')' :
            priority = 3;
            break;
        default :
            break;
    }
    return priority;
}


Suffix::Suffix(string s) {
    infix = s;
}

string Suffix::change() {
    string suffix = infix;
    int j = 0;
    stack<char> operatorStack;
    for (int i = 0; infix[i] != '#'; i++) {
        if (Util::checkNum(infix[i])) {
            suffix[j] = infix[i];
            j++;
        }
        else {
            if (!Util::checkRBracket(infix[i])) {
                while (!checkStack(infix[i], operatorStack) && operatorStack.top() != '(') {
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();

                }
                operatorStack.push(infix[i]);
            }
            else {
                while (operatorStack.top() != '(') {
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
        }
    }
    while (!operatorStack.empty()) {
        suffix[j] = operatorStack.top();
        j++;
        operatorStack.pop();
    }

    suffix[j] = '@';

    int size = suffix.find('@', 0);
    string subSuffix = suffix.substr(0, size);
    subSuffix += '#';

    return subSuffix;
}


