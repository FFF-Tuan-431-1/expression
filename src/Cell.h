//
// Created by NiL on 15/3/17.
//

#ifndef _EXPRESSION_CELL_H_
#define _EXPRESSION_CELL_H_


class Cell {
public:
    //存放数字
    int number;

    //存放操作符
    char opt;

    //构造函数
    Cell();
    Cell(int t_num);
    Cell(char t_opt);

    //判断方法
    bool isNumber();
    bool isOperator();
    bool isLeftBracket();
    bool isRightBracket();
};


#endif //_EXPRESSION_CELL_H_
