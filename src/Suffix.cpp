//
// Created by xiaowei on 2015/3/15.
//

#include "Suffix.h"
#include "Cell.h"
#include "Util.h"

#include<stack>
#include<string>

#include <iostream>

using namespace std;

Suffix::Suffix(string infix): infix(infix) {

    m_tree = NULL;
    m_tree = createTree();
}

Node * Suffix::createTree() {
    stack<char> operatorStack;
    stack<Node *> treeStack;

    int i = 0;
    int temp = -1;
    char ch = infix[i++];

    while(operatorStack.size()!=0 || ch != '#') {
        if (ch != '#' && Util::isNumber(ch)) {
            if (temp == -1) temp = 0;
            temp = temp * 10 + ch - '0';
            ch = infix[i++];
        } else {
            if (temp != -1) {
                Node * p = new Node;
                p->data = Cell(temp);
                temp = -1;
                treeStack.push(p);
            }
            switch (ch) {
                case '(':
                    operatorStack.push('(');
                    ch = infix[i++];
                    break;
                case ')':
                    while (true) {
                        char tmp = operatorStack.top();
                        operatorStack.pop();
                        if (tmp == '(') {
                            break;
                        }

                        Node * p = new Node;
                        p->data = Cell(tmp);
                        if (treeStack.size()) {
                            p->right = treeStack.top();
                            treeStack.pop();
                        }
                        if (treeStack.size()) {
                            p->left = treeStack.top();
                            treeStack.pop();
                        }
                        treeStack.push(p);
                    }
                    ch = infix[i++];
                    break;
                default:
                    if (operatorStack.size() == 0 || ch != '#' && Util::getPriority(operatorStack.top()) < Util::getPriority(ch)) {
                        operatorStack.push(ch);
                        ch = infix[i++];
                    } else {
                        Node * p = new Node;
                        p->data = Cell(operatorStack.top());
                        operatorStack.pop();

                        if (treeStack.size()) {
                            p->right = treeStack.top();
                            treeStack.pop();
                        }
                        if (treeStack.size()) {
                            p->left = treeStack.top();
                            treeStack.pop();
                        }
                        treeStack.push(p);
                    }

            }
        }
    }

    if (temp != -1) {
        Node * p = new Node;
        p->data = Cell(temp);
        temp = 0;
        treeStack.push(p);
    }

    return treeStack.top();

}

void Suffix::lastSearch(Node *tree, vector<Cell> & suffix) {
    if (tree == NULL) return;

    lastSearch(tree->left, suffix);
    lastSearch(tree->right, suffix);
    suffix.push_back(tree->data);

}


vector<Cell> Suffix::getSuffix() {
    vector<Cell> suffix;
    Node * tree = m_tree;
    lastSearch(tree, suffix);
    return suffix;
}