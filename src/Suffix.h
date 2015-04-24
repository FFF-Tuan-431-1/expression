//
// Created by xiaowei on 2015/3/15.
//

#ifndef _EXPRESSION_SUFFIX_H_
#define _EXPRESSION_SUFFIX_H_

#include<string>
#include<stack>
#include<vector>

#include "Cell.h"

using namespace std;

struct Node {
    struct Node * left = NULL, * right = NULL;
    struct Cell data = Cell();
};

class Suffix {
public:
    //构造函数
    Suffix(string infix);

    //实行将中缀表达式转变成后缀表达式
    vector<Cell> getSuffix();

private:
    //将要被转后缀的中缀表达式（以数组形式存储）
    string infix;
    Node * createTree();
    bool visited[10000] = {false};
    void lastSearch(Node *tree, vector<Cell> & suffix);

    //bool checkStack(Cell optCell, stack<Cell> tempStack);

    int getPriority(char opt);
    Node * m_tree;
};


#endif //_EXPRESSION_SUFFIX_H_
