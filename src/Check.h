//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_CHECK_H_
#define _COLLEGETWO_CHECK_H_

#include<string>

using namespace std;

class Check {
public:
    //���캯��
    Check(string s);

    //����������׺���ʽ�Ƿ��д�
    bool checkError();

private:
    //��Ҫ��������׺���ʽ
    string infix;

    //��ǰ�ַ�Ϊ���ֵ�״̬
    bool stateNum(int i, int &lb);

    //��ǰ�ַ�Ϊ��������״̬
    bool stateOper(int i, int &lb);

    //��ǰ�ַ�Ϊ�����ŵ�״̬
    bool stateLBra(int i, int &lb);

    //��ǰ�ַ�Ϊ�����ŵ�״̬
    bool stateRBra(int i, int &lb);
};


#endif //_COLLEGETWO_CHECK_H_
