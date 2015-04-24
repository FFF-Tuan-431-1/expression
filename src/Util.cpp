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

int Util::getPriority(char opt)
{
    switch(opt)
    {
        case '(':
            return 1; break;
        case '+':
        case '-':
            return 2; break;
        case '*':
        case '/':
            return 3; break;
        default:
            return 0;
    }
}

std::string Util::intToString(int number) {
    std::stringstream t;
    t << number;
    return t.str();
}