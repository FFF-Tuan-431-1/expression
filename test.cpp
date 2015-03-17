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

    calculate.setExpression("1(");
    assert(calculate.isError());

    calculate.setExpression("((2+2))");
    assert(!calculate.isError());


    //判断正误
    calculate.setExpression("1+1");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 2);

    calculate.setExpression("1+(2*3)");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 7);

    calculate.setExpression("((2*2)+(2*3))+5");
    assert(!calculate.isError());
    assert(calculate.getAnswer()  == 15);

    cout<<"Test Passed!"<<endl;

}