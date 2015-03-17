//
// Created by xiaowei on 2015/3/15.
//

#include "Suffix.h"
#include "Cell.h"
#include "Util.h"

#include<stack>
#include<string>

#include <iostream>

using namespace std;

bool Suffix::checkStack(Cell optCell, stack<Cell> tempStack) {
    return tempStack.empty() || Cell::checkPriority(optCell, tempStack.top());
}

Suffix::Suffix(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (Util::isNumber(s[i])) {
            if(!infix.empty() && infix.back().isNumber()) {
                infix.back().number = infix.back().number * 10 + (s[i] - '0');
            }
            else {
                infix.push_back(Cell(s[i] - '0'));
            }
        }
        else {
            infix.push_back(Cell(s[i]));
        }
    }
}

vector<Cell> Suffix::getSuffix() {
    vector<Cell> suffix(infix);

    int j = 0;
    stack<Cell> operatorStack;

    for (int i = 0; i < infix.size(); i++) {
        if (infix[i].isNumber()) {
            suffix[j] = infix[i];
            j++;
        }
        else {
            if (!infix[i].isRightBracket()) {
                while (!checkStack(infix[i], operatorStack) && !operatorStack.top().isLeftBracket()) {
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();

                }
                operatorStack.push(infix[i]);
            }
            else {
                while (!operatorStack.top().isLeftBracket()) {
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

    suffix.resize(j - 1);

    return suffix;
}


