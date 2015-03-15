//
// Created by xiaowei on 2015/3/15.
//

#include "Util.h"


bool Util::checkNum(char ch) {
    if ('0' <= ch && ch <= '9')
        return true;
    else
        return false;
}

bool Util::checkOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

bool Util::checkLBracket(char ch) {
    if (ch == '(')
        return true;
    else
        return false;
}

bool Util::checkRBracket(char ch) {
    if (ch == ')')
        return true;
    else
        return false;
}
