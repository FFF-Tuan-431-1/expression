//
// Created by xiaowei on 2015/3/15.
//

#include <sstream>
#include "Util.h"


bool Util::isNumber(char ch) {
    if ('0' <= ch && ch <= '9')
        return true;
    else
        return false;
}

bool Util::isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

bool Util::isLeftBracket(char ch) {
    if (ch == '(')
        return true;
    else
        return false;
}

bool Util::isRightBracket(char ch) {
    if (ch == ')')
        return true;
    else
        return false;
}

std::string Util::intToString(int number) {
    std::stringstream t;
    t << number;
    return t.str();
}