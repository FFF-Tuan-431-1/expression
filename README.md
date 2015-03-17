# 文档

## 测试文件

````
test.cpp, 用于测试Calculate类的行为

```
## class Util//自定义工具函数类
````
public:
    //判断是否为数字
    static bool isNumber(char ch);

    //判断是否为操作符
    static bool isOperator(char ch);

    //判断是否为左括号
    static bool isLeftBracket(char ch);

    //判断是否为右括号
    static bool isRightBracket(char ch);

````

## class Suffix//自定义转后缀功能类
````
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

````

## class Check//自定义检错类
````
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

````

## class Calculate //自定义计算器类
````
public:
    //构造函数
    Calculate(string s);

    //设置需要计算的表达式
    void setExpression(string s);

    //计算当前后缀表达式的值
    int getAnswer();

    //判断算式是否错误
    bool isError();

private:
    //输入的将要被求值的中缀表达式
    string infix;

    //将字符类型的数字转换成整型
    int charToInt(char ch);

    //计算数值a和数值b的(operate)操作
    int calculate(char opera, int a, int b);
    
````
