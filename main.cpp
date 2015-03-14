#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;

string change(string infix, string suffix);

bool checkNum(char ch);

bool checkOperator(char ch);

bool checkLBracket(char ch);

bool checkRBracket(char ch);

bool checkStack(char ch, stack<char> tempStack);

bool checkPriority(char one, char two);

int getPriority(char temp);

int getValue(string suffix);

int charToInt(char ch);

int calculate(char opera, int a, int b);

bool checkError(string infix);

bool stateNum(string infix, int i, int &lb);

bool stateOper(string infix, int i, int &lb);

bool stateLBra(string infix, int i, int &lb);

bool stateRBra(string infix, int i, int &lb);

int main() {
    string expression;

    cin >> expression;
    expression += '#';

    while (!checkError(expression)) {
        cout << "error" << endl << "input again" << endl;
        cin >> expression;
        expression += '#';
    }
    string suffixExpression = expression;

    suffixExpression = change(expression, suffixExpression);

    cout << suffixExpression << endl;

    int result = getValue(suffixExpression);
    cout << result;

    return 0;
}

bool checkNum(char ch) {
    if ('0' <= ch && ch <= '9')
        return true;
    else
        return false;
}

bool checkOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

bool checkLBracket(char ch) {
    if (ch == '(')
        return true;
    else
        return false;
}

bool checkRBracket(char ch) {
    if (ch == ')')
        return true;
    else
        return false;
}

bool checkStack(char ch, stack<char> tempStack) {
    if (tempStack.empty() == true || checkPriority(ch, tempStack.top()) == true)
        return true;
    else
        return false;
}

bool checkPriority(char one, char two) {
    if (getPriority(one) > getPriority(two))
        return true;
    else
        return false;
}

int getPriority(char temp) {
    int priority = 0;
    switch (temp) {
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


string change(string infix, string suffix) {
    int j = 0;
    stack<char> operatorStack;
    for (int i = 0; infix[i] != '#'; i++) {
        if (checkNum(infix[i])) {
            suffix[j] = infix[i];
            j++;
        }
        else {
            if (!checkRBracket(infix[i])) {
                while (!checkStack(infix[i], operatorStack) && operatorStack.top() != '(') {
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();

                }
                operatorStack.push(infix[i]);
            }
            else {
                while (operatorStack.top() != '(') {
                    suffix[j] = operatorStack.top();
                    j++;
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
        }
    }
    while (!operatorStack.empty()) {
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

int getValue(string suffix) {
    stack<int> numberStack;

    for (int i = 0; suffix[i] != '#'; i++) {
        if (checkNum(suffix[i]))
            numberStack.push(charToInt(suffix[i]));
        else {
            int b = numberStack.top();
            numberStack.pop();
            int a = numberStack.top();
            numberStack.pop();
            numberStack.push(calculate(suffix[i], a, b));
        }
    }

    return numberStack.top();
}

int charToInt(char ch) {
    int num;
    num = (int) (ch - '0');
    return num;
}

int calculate(char opera, int a, int b) {
    int result = 0;

    switch (opera) {
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

bool checkError(string infix) {
    bool error = true;
    int leftBracket = 0;

    if (checkNum(infix[0])) {
        error = stateNum(infix, 0, leftBracket);
    }
    else if (checkLBracket(infix[0])) {
        error = stateLBra(infix, 0, leftBracket);
    }
    else
        error = false;

    if (error == true && leftBracket == 0)
        return true;
    else
        return false;


}

bool stateNum(string infix, int i, int &lb) {
    bool error;

    i++;

    if (infix[i] != '#') {
        if (checkOperator(infix[i])) {
            error = stateOper(infix, i, lb);
        }
        else if (checkRBracket(infix[i])) {
            error = stateRBra(infix, i, lb);
        }
        else
            error = false;
    }
    else
        error = true;

    return error;
}

bool stateOper(string infix, int i, int &lb) {
    bool error;

    i++;

    if (infix[i] != '#') {
        if (checkNum(infix[i])) {
            error = stateNum(infix, i, lb);
        }
        else if (checkLBracket(infix[i])) {
            error = stateLBra(infix, i, lb);
        }
        else
            error = false;
    }
    else
        error = false;

    return error;

}

bool stateLBra(string infix, int i, int &lb) {
    bool error;

    i++;
    lb++;

    if (infix[i] != '#') {
        if (checkNum(infix[i])) {
            error = stateNum(infix, i, lb);
        }
        else
            error = false;
    }
    else
        error = false;

    return error;
}

bool stateRBra(string infix, int i, int &lb) {
    bool error;

    i++;
    lb--;

    if (infix[i] != '#') {
        if (checkOperator(infix[i])) {
            error = stateOper(infix, i, lb);
        }
        else
            error = false;
    }
    else
        error = true;

    return error;
}