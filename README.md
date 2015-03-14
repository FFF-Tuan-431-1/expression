# 文档

## 子函数功能

````
void printff(stack<int> c);//打印栈中所有元素
string change(string infix, string suffix);//实行将中缀表达式转变成后缀表达式
bool checkNum(char ch);//判断是否为数字
bool checkOperator(char ch);//判断是否为操作符
bool checkLBracket(char ch);//判断是否为左括号
bool checkRBracket(char ch);//判断是否为右括号
bool checkStack(char ch, stack<char> tempStack);//判断是否将当前的操作符入栈
bool checkPriority(char one, char two);//比较这两个操作符的优先级
int getPriority(char temp);//获取当前操作符的优先级别
int getValue(string suffix);//计算当前后缀表达式的值
int charToInt(char ch);//将字符类型的数字转换成整型
int calculate(char opera, int a, int b);//计算数值a和数值b的(operate)操作
bool checkError(string infix);//检查输入的中缀表达式是否有错
bool stateNum(string infix, int i, int& lb);//当前字符为数字的状态
bool stateOper(string infix, int i, int& lb);//当前字符为操作符的状态
bool stateLBra(string infix, int i, int& lb);//当前字符为左括号的状态
bool stateRBra(string infix, int i, int& lb);//当前字符为右括号的状态
````