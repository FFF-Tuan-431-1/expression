#include<cstdlib>
#include<iostream>
#include<cassert>

#include "src/Calculate.h"

using namespace std;

int main() {
    //错误判断
    //输入的式子中操作符两边必须有数据
    Calculate calculate("1+");
    assert(calculate.isError());
    //不得使用括号的非法用法
    calculate.setExpression("(1");
    assert(calculate.isError());
    //任何以右括号为开头的表达式都是非法的
    calculate.setExpression(")");
    assert(calculate.isError());
    //一个合法表达式两边加任意数量合法的左右括号是合法的
    calculate.setExpression("((2+2))");
    assert(!calculate.isError());
    //括号中必须有合法表达式或者数字
    calculate.setExpression("()");
    assert(calculate.isError());
    //左括号之后的第一个字符必须是数字
    calculate.setExpression("(*");
    assert(calculate.isError());
    //两个操作符连接在一起使用是非法的
    calculate.setExpression("+-");
    assert(calculate.isError());
    //只输入数据不输入操作符是合法的
    calculate.setExpression("1");
    assert(!calculate.isError());
    //只输入操作符是非法的
    calculate.setExpression("+");
    assert(calculate.isError());
    //左右括号数量不一致是非法的
    calculate.setExpression("(2+3))");
    assert(calculate.isError());
    //一个完整括号中只有数据是合法的
    calculate.setExpression("(22)");
    assert(!calculate.isError());
    //0当做除数是非法的
//    calculate.setExpression("2/0");
//    assert(calculate.isError());
    //可以进行负数运算
//    calculate.setExpression("-2");
//    assert(!calculate.isError());

    //判断正误
    //1.在输入合法的情况下，判定经计算器程序处理的等式结果是否是正确的
    //2.判断输出的后缀表达式是否正确
    calculate.setExpression("1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 1);
    assert(calculate.getSuffix() == "1");

    calculate.setExpression("1+1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 2);
    assert(calculate.getSuffix() == "1 1 +");

    calculate.setExpression("1+(2*3)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 7);
    assert(calculate.getSuffix() == "1 2 3 * +");

    calculate.setExpression("((2*2)+(2*3))+5");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 15);
    assert(calculate.getSuffix() == "2 2 * 2 3 * + 5 +");


    calculate.setExpression("1/2");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 0);
    assert(calculate.getSuffix() == "1 2 /");

    calculate.setExpression("0/2");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 0);
    assert(calculate.getSuffix() == "0 2 /");

//    calculate.setExpression("7*(4+7*(1-2)/2)");
//    assert(!calculate.isError());
//    assert(calculate.getAnswer()  == 0);
//    assert(calculate.getSuffix() == "7 4 7 1 2 - * 2 / + *");

    calculate.setExpression("22");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 22);
    assert(calculate.getSuffix() == "22");

    calculate.setExpression("22-1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 21);
    assert(calculate.getSuffix() == "22 1 -");

    calculate.setExpression("1-22");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == -21);
    assert(calculate.getSuffix() == "1 22 -");

    calculate.setExpression("22+11");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 33);
    assert(calculate.getSuffix() == "22 11 +");

    calculate.setExpression("11*(22+1/2)-(12+1)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 229);
    assert(calculate.getSuffix() == "11 22 1 2 / + * 12 1 + -");

    cout<<"Test Passed!"<<endl;

}