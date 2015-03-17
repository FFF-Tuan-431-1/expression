//
// Created by xiaowei on 2015/3/15.
//

#ifndef _EXPRESSION_SUFFIX_H_
#define _EXPRESSION_SUFFIX_H_

#include<string>
#include<stack>
#include<vector>

#include "Cell.h"

using namespace std;

class Suffix {
public:
    //构造函数
    Suffix(string infix);

    //实行将中缀表达式转变成后缀表达式
    vector<Cell> getSuffix();

private:
    //将要被转后缀的中缀表达式（以数组形式存储）
    vector<Cell> infix;

    //判断是否将当前的操作符入栈
    bool checkStack(Cell optCell, stack<Cell> tempStack);
};


#endif //_EXPRESSION_SUFFIX_H_
