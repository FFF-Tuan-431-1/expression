//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_CALCULATE_H_
#define _COLLEGETWO_CALCULATE_H_

#include<string>
#include<stack>

using namespace std;

class Calculate {
public:
    //构造函数
    Calculate(string s);

    //改变中缀表达式
    void inspirit(string s);

    //打印中缀表达式
    void pri();

    //计算当前后缀表达式的值
    int getValue();

    //进行工作
    void work();

private:
    //输入的将要被求值的中缀表达式
    string infix;

    //将字符类型的数字转换成整型
    int charToInt(char ch);

    //计算数值a和数值b的(operate)操作
    int calculate(char opera, int a, int b);
};


#endif //_COLLEGETWO_CALCULATE_H_