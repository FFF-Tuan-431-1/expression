//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_CHECK_H_
#define _COLLEGETWO_CHECK_H_

#include<string>

using namespace std;

class Check {
public:
    //构造函数
    Check(string s);

    //检查输入的中缀表达式是否有错
    bool checkError();

private:
    //将要被检错的中缀表达式
    string infix;

    //当前字符为数字的状态
    bool stateNum(int i, int &lb);

    //当前字符为操作符的状态
    bool stateOper(int i, int &lb);

    //当前字符为左括号的状态
    bool stateLBra(int i, int &lb);

    //当前字符为右括号的状态
    bool stateRBra(int i, int &lb);
};


#endif //_COLLEGETWO_CHECK_H_
