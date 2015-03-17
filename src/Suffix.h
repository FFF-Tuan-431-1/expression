//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_SUFFIX_H_
#define _COLLEGETWO_SUFFIX_H_

#include<string>
#include<stack>

using namespace std;

class Suffix {
public:
    //构造函数
    Suffix(string s);

    //实行将中缀表达式转变成后缀表达式
    string getSuffix();

private:
    //将要被转后缀的中缀表达式
    string infix;

    //判断是否将当前的操作符入栈
    bool checkStack(char ch, stack<char> tempStack);

    //比较这两个操作符的优先级
    bool checkPriority(char first, char second);

    //获取当前操作符的优先级别
    int getPriority(char temp);
};


#endif //_COLLEGETWO_SUFFIX_H_
