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
    return number == -1 && !isRightBracket() && !isLeftBracket();
}