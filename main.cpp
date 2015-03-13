#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;

void printff(stack<int> c);
string change(string infix, string suffix);
bool checkNum(char ch);
bool checkOperator(char ch);
bool checkBracket(char ch);
bool checkStack(char ch, stack<char> tempStack);
bool checkPriority(char one, char two);
int getPriority(char temp);
int getValue(string suffix);
int charToInt(char ch);
int calculate(char opera, int a, int b);

int main(){
    string expression;

    cin>> expression;
    expression += '#';

    string suffixExpression = expression;

    suffixExpression = change(expression, suffixExpression);

    //cout<<expression<<endl;
    cout<<suffixExpression<<endl;

    int j = getValue(suffixExpression);
    cout<<j;

    return 0;
}

void printff(stack<int> c){
    while(!c.empty()){
        cout << c.top() << " ";
        c.pop();
    }
    cout<<endl;
}

bool checkNum(char ch){
    if ('0' <= ch && ch <= '9')
        return true;
    else
        return false;
}

bool checkOperator(char ch){
    if ( ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

bool checkBracket(char ch){
    if (ch == ')')
        return true;
    else
        return false;
}

bool checkStack(char ch, stack<char> tempStack){
    if(tempStack.empty() == true || checkPriority(ch, tempStack.top()) == true)
        return true;
    else
        return false;
}

bool checkPriority(char one, char two){
    if(getPriority(one) > getPriority(two))
        return true;
    else
        return false;
}

int getPriority(char temp){
    int priority = 0;
    switch (temp){
        case '+' :
            priority = 1;
            break;
        case '-' :
            priority = 1;
            break;
        case '*' :
            priority = 2;
            break;
        case '/' :
            priority = 2;
            break;
        case '(' :
            priority = 3;
            break;
        case ')' :
            priority = 3;
            break;
        default :
            break;
    }
    return priority;
}


string change(string infix, string suffix){
    int j = 0;
    stack<char> operatorStack;
    for(int i = 0; infix[i] != '#'; i++){
        if(checkNum(infix[i])){
            suffix[j] = infix[i];
            j++;
        }
        else{
            if(!checkBracket(infix[i])){
                while(checkStack(infix[i], operatorStack) == false && operatorStack.top() != '('){
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();

                }
                operatorStack.push(infix[i]);
            }
            else{
                while(operatorStack.top() != '('){
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
        }
    }
    while(!operatorStack.empty()){
        suffix[j] = operatorStack.top();
        j++;
        operatorStack.pop();
    }

    suffix[j] = '@';

    int size = suffix.find('@', 0);
    string subSuffix = suffix.substr(0, size);
    subSuffix += '#';

    return subSuffix;
}

int getValue(string suffix){
    stack<int> numberStack;

    for(int i = 0; suffix[i] != '#'; i++){
        if(checkNum(suffix[i]))
            numberStack.push(charToInt(suffix[i]));
        else{
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            numberStack.push(calculate(suffix[i], a, b));
        }
    }

    return numberStack.top();
}

int charToInt(char ch){
    int num;
    num = (int)(ch - '0');
    return num;
}

int calculate(char opera, int a, int b){
    int result = 0;

    switch (opera){
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
    }

    return result;
}