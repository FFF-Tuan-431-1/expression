//
// Created by xiaowei on 2015/3/15.
//


#include "Check.h"
#include "Util.h"
#include "Cell.h"
#include<string>

using namespace std;

bool Check::stateNum(int i, int &lb) {
    bool error;

    i++;

    if (infix[i] != '#') {
        if (Util::isNumber(infix[i])) {
            error = stateNum(i, lb);
        }
        else if (Util::isOperator(infix[i])) {
            error = stateOper(i, lb);
        }
        else if (Util::isRightBracket(infix[i])) {
            error = stateRBra(i, lb);
        }
        else
            error = false;
    }
    else
        error = true;

    return error;
}

bool Check::stateOper(int i, int &lb) {
    bool error;

    i++;

    if (infix[i] != '#') {
        if (Util::isNumber(infix[i])) {
            error = stateNum(i, lb);
        }
        else if (Util::isLeftBracket(infix[i])) {
            error = stateLBra(i, lb);
        }
        else
            error = false;
    }
    else
        error = false;

    return error;

}

bool Check::stateLBra(int i, int &lb) {
    bool error;

    i++;
    lb++;

    if (infix[i] != '#') {
        if (Util::isNumber(infix[i])) {
            error = stateNum(i, lb);
        }
        else if (Util::isLeftBracket(infix[i])) {
            error = stateLBra(i, lb);
        }
        else
            error = false;
    }
    else
        error = false;

    return error;
}

bool Check::stateRBra(int i, int &lb) {
    bool error;

    i++;
    lb--;

    if (infix[i] != '#') {
        if (Util::isOperator(infix[i])) {
            error = stateOper(i, lb);
        }
        else if (Util::isRightBracket(infix[i])) {
            error = stateRBra(i, lb);
        }
        else
            error = false;
    }
    else
        error = true;

    return error;
}

Check::Check(string s) {
    infix = s;
}

bool Check::checkError() {
    bool error = true;
    int leftBracket = 0;

    if (Util::isNumber(infix[0])) {
        error = stateNum(0, leftBracket);
    }
    else if (Util::isLeftBracket(infix[0])) {
        error = stateLBra(0, leftBracket);
    }
    else
        error = false;

    if (error == true && leftBracket == 0)
        return true;
    else
        return false;
}
