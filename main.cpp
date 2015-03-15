#include<cstdlib>
#include<iostream>
#include<stack>

using namespace std;

class Util {
public:
    static bool checkNum(char ch) {
        if ('0' <= ch && ch <= '9')
            return true;
        else
            return false;
    }

    static bool checkOperator(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return true;
        else
            return false;
    }

    static bool checkLBracket(char ch) {
        if (ch == '(')
            return true;
        else
            return false;
    }

    static bool checkRBracket(char ch) {
        if (ch == ')')
            return true;
        else
            return false;
    }
};

class Suffix{
private:
    string infix;

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


public:
    Suffix(string s){
        infix = s;
    }

    string change() {
        string suffix = infix;
        int j = 0;
        stack<char> operatorStack;
        for (int i = 0; infix[i] != '#'; i++) {
            if (Util::checkNum(infix[i])) {
                suffix[j] = infix[i];
                j++;
            }
            else {
                if (!Util::checkRBracket(infix[i])) {
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


};

class Check{
private:
    string infix;
    bool stateNum(int i, int &lb) {
        bool error;

        i++;

        if (infix[i] != '#') {
            if (Util::checkOperator(infix[i])) {
                error = stateOper(i, lb);
            }
            else if (Util::checkRBracket(infix[i])) {
                error = stateRBra(i, lb);
            }
            else
                error = false;
        }
        else
            error = true;

        return error;
    }

    bool stateOper(int i, int &lb) {
        bool error;

        i++;

        if (infix[i] != '#') {
            if (Util::checkNum(infix[i])) {
                error = stateNum(i, lb);
            }
            else if (Util::checkLBracket(infix[i])) {
                error = stateLBra(i, lb);
            }
            else
                error = false;
        }
        else
            error = false;

        return error;

    }

    bool stateLBra(int i, int &lb) {
        bool error;

        i++;
        lb++;

        if (infix[i] != '#') {
            if (Util::checkNum(infix[i])) {
                error = stateNum(i, lb);
            }
            else
                error = false;
        }
        else
            error = false;

        return error;
    }

    bool stateRBra(int i, int &lb) {
        bool error;

        i++;
        lb--;

        if (infix[i] != '#') {
            if (Util::checkOperator(infix[i])) {
                error = stateOper(i, lb);
            }
            else
                error = false;
        }
        else
            error = true;

        return error;
    }
public:
    Check(string s){
        infix = s;
    }

    bool checkError() {
        bool error = true;
        int leftBracket = 0;

        if (Util::checkNum(infix[0])) {
            error = stateNum(0, leftBracket);
        }
        else if (Util::checkLBracket(infix[0])) {
            error = stateLBra(0, leftBracket);
        }
        else
            error = false;

        if (error == true && leftBracket == 0)
            return true;
        else
            return false;
    }
};

class Calculate {
private:
    string infix;

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

public:
    Calculate(string s) {
        infix = s + '#';
    }

    void inspirit(string s) {
        infix = s + '#';
    }


    void pri() {
        cout << infix << endl;
    }

    int getValue() {
        stack<int> numberStack;

        Suffix suffix(infix);
        string suffixExpression = suffix.change();
        for (int i = 0; suffixExpression[i] != '#'; i++) {
            if (Util::checkNum(suffixExpression[i]))
                numberStack.push(charToInt(suffixExpression[i]));
            else {
                int b = numberStack.top();
                numberStack.pop();
                int a = numberStack.top();
                numberStack.pop();
                numberStack.push(calculate(suffixExpression[i], a, b));
            }
        }

        return numberStack.top();
    }

    void work(){
        Check check(infix);

        if(check.checkError()){
            cout<<getValue()<<endl;
        }
        else
            cout<<"error"<<endl;
    }

};

int main() {
    string input;

    cin >> input;
    Calculate calculate(input);
    calculate.work();

}