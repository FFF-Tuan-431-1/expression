//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_SUFFIX_H_
#define _COLLEGETWO_SUFFIX_H_

#include<string>
#include<stack>

using namespace std;

class Suffix {
public:
    //���캯��
    Suffix(string s);

    //ʵ�н���׺���ʽת��ɺ�׺���ʽ
    string change();

private:
    //��Ҫ��ת��׺����׺���ʽ
    string infix;

    //�ж��Ƿ񽫵�ǰ�Ĳ�������ջ
    bool checkStack(char ch, stack<char> tempStack);

    //�Ƚ������������������ȼ�
    bool checkPriority(char one, char two);

    //��ȡ��ǰ�����������ȼ���
    int getPriority(char temp);
};


#endif //_COLLEGETWO_SUFFIX_H_
