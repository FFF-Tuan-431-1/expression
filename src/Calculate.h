//
// Created by xiaowei on 2015/3/15.
//

#ifndef _COLLEGETWO_CALCULATE_H_
#define _COLLEGETWO_CALCULATE_H_

#include<string>
#include<stack>

using namespace std;

class Calculate {
public:
    //���캯��
    Calculate(string s);

    //�ı���׺���ʽ
    void inspirit(string s);

    //��ӡ��׺���ʽ
    void pri();

    //���㵱ǰ��׺���ʽ��ֵ
    int getValue();

    //���й���
    void work();

private:
    //����Ľ�Ҫ����ֵ����׺���ʽ
    string infix;

    //���ַ����͵�����ת��������
    int charToInt(char ch);

    //������ֵa����ֵb��(operate)����
    int calculate(char opera, int a, int b);
};


#endif //_COLLEGETWO_CALCULATE_H_
