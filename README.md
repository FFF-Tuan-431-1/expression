# 文档

## class Calculate //自定义计算器类
````
private:
string infix;//输入的将要被求值的中缀表达式
bool checkNum(char ch);//判断是否为数字
bool checkOperator(char ch);//判断是否为操作符
bool checkBracket(char ch);//判断是否为括号
bool checkStack(char ch, stack<char> tempStack);//判断是否将当前的操作符入栈
bool checkPriority(char one, char two);//比较这两个操作符的优先级
int getPriority(char temp);//获取当前操作符的优先级别
int charToInt(char ch);//将字符类型的数字转换成整型
int calculate(char opera, int a, int b);//计算数值a和数值b的(operate)操作
bool stateNum(int i, int& lb);//当前字符为数字的状态
bool stateOper(int i, int& lb);//当前字符为操作符的状态
bool stateLBra(int i, int& lb);//当前字符为左括号的状态
bool stateRBra(int i, int& lb);//当前字符为右括号的状态

public:
void inspirit(string s);//改变中缀表达式
void pri();//打印中缀表达式
string change();//实行将中缀表达式转变成后缀表达式
int getValue();//计算当前后缀表达式的值
bool checkError();//检查输入的中缀表达式是否有错

````