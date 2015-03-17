//
// Created by NiL on 15/3/17.
//

#include "Cell.h"

Cell::Cell() {
    number = -1;
    opt = 'x';
}

Cell::Cell(int t_num) {
    number = t_num;
    opt = 'x';
}

Cell::Cell(char t_opt) {
    number = -1;
    opt = t_opt;
}

bool Cell::isNumber() {
    return number != -1;
}

bool Cell::isLeftBracket() {
    return opt == '(';
}

bool Cell::isRightBracket() {
    return opt == ')';
}
bool Cell::isOperator() {
    return !number && !isRightBracket() && !isLeftBracket();
}

int Cell::getPriority() {
    int priority = 0;
    switch (opt) {
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

bool Cell::checkPriority(Cell first, Cell second) {
    return  first.getPriority() > second.getPriority();
}