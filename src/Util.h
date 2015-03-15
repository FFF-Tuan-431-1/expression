//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_UTIL_H_
#define _COLLEGETWO_UTIL_H_


class Util {
public:
    //判断是否为数字
    static bool checkNum(char ch);

    //判断是否为操作符
    static bool checkOperator(char ch);

    //判断是否为左括号
    static bool checkLBracket(char ch);

    //判断是否为右括号
    static bool checkRBracket(char ch);
};


#endif //_COLLEGETWO_UTIL_H_
