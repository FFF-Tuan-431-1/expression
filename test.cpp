#include<cstdlib>
#include<iostream>
#include<cassert>

#include "src/Calculate.h"

using namespace std;

int main() {
    //错误判断
    Calculate calculate("1+");
    assert(calculate.isError());

    calculate.setExpression("(1");
    assert(calculate.isError());

    calculate.setExpression(")");
    assert(calculate.isError());

    calculate.setExpression("1(");
    assert(calculate.isError());

    calculate.setExpression("((2+2))");
    assert(!calculate.isError());

    calculate.setExpression("()");
    assert(calculate.isError());

    calculate.setExpression("(*");
    assert(calculate.isError());

    calculate.setExpression("(/");
    assert(calculate.isError());

    calculate.setExpression("(+");
    assert(calculate.isError());

    calculate.setExpression("(-");
    assert(calculate.isError());

    calculate.setExpression("+-");
    assert(calculate.isError());

    calculate.setExpression("*/");
    assert(calculate.isError());

    calculate.setExpression("-+");
    assert(calculate.isError());

    calculate.setExpression("++");
    assert(calculate.isError());

    calculate.setExpression("--");
    assert(calculate.isError());

    calculate.setExpression("**");
    assert(calculate.isError());

    calculate.setExpression("//");
    assert(calculate.isError());

    calculate.setExpression("+*");
    assert(calculate.isError());

    calculate.setExpression("+/");
    assert(calculate.isError());

    calculate.setExpression("-*");
    assert(calculate.isError());

    calculate.setExpression("-/");
    assert(calculate.isError());

    calculate.setExpression("*+");
    assert(calculate.isError());

    calculate.setExpression("*-");
    assert(calculate.isError());

    calculate.setExpression("/*");
    assert(calculate.isError());

    calculate.setExpression("/+");
    assert(calculate.isError());

    calculate.setExpression("/-");
    assert(calculate.isError());

    calculate.setExpression("()");
    assert(calculate.isError());

    calculate.setExpression("1");
    assert(!calculate.isError());

    calculate.setExpression("+");
    assert(calculate.isError());

    calculate.setExpression("-");
    assert(calculate.isError());

    calculate.setExpression("*");
    assert(calculate.isError());

    calculate.setExpression("/");
    assert(calculate.isError());

    calculate.setExpression("(2+3))");
    assert(calculate.isError());

    calculate.setExpression("((2+3)");
    assert(calculate.isError());

    calculate.setExpression("22");
    assert(!calculate.isError());

    calculate.setExpression("(22)");
    assert(!calculate.isError());

    calculate.setExpression("(+)");
    assert(calculate.isError());

    calculate.setExpression("2/0");
    assert(calculate.isError());

    //判断正误

    calculate.setExpression("1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 1);

    calculate.setExpression("1+1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 2);

    calculate.setExpression("1+(2*3)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 7);

    calculate.setExpression("((2*2)+(2*3))+5");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 15);

    calculate.setExpression("1/2");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 0);

    calculate.setExpression("0/2");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 0);

    calculate.setExpression("7*(4+7*(1-2)/2)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 0);

    calculate.setExpression("22");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 22);

    calculate.setExpression("22-1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 21);

    calculate.setExpression("1-22");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == -21);

    calculate.setExpression("22+11");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 33);

    calculate.setExpression("11*(22+1/2)-(12+1)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 229);

    cout<<"Test Passed!"<<endl;

}