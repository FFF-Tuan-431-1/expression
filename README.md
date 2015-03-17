# 文档

## 测试文件

````
test.cpp, 用于测试Calculate类的行为

```

## class Calculate //自定义计算器类
````
public:
    //构造函数
    Calculate(string s);

    //设置需要计算的表达式
    void setExpression(string s);

    //计算当前后缀表达式的值
    int getAnswer();

    //返回后缀表达式
    string getSuffix();

    //判断算式是否错误
    bool isError();

private:
    //输入的将要被求值的中缀表达式
    string infix;

    //计算数值a和数值b的(operate)操作
    int calculate(char opera, int a, int b);
    
````

## class Suffix//自定义转后缀功能类
````
public:
    //构造函数
    Suffix(string infix);

    //实行将中缀表达式转变成后缀表达式
    vector<Cell> getSuffix();

private:
    //将要被转后缀的中缀表达式（以数组形式存储）
    vector<Cell> infix;

    //判断是否将当前的操作符入栈
    bool checkStack(Cell optCell, stack<Cell> tempStack);
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

## Class Cell //存数据的类
````
public:
    //存放数字
    int number;

    //存放操作符
    char opt;

    //构造函数
    Cell();
    Cell(int t_num);
    Cell(char t_opt);
    
    //判断方法
    bool isNumber();
    bool isOperator();
    bool isLeftBracket();
    bool isRightBracket();

    //比较操作符优先级
    static bool checkPriority(Cell first, Cell second);
private:
    //获取操作符优先级
    int getPriority();
   
````


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

     //将int转换成string类型
        static std::string intToString(int number);

````