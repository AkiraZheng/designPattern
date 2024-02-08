#pragma once
#include "header.h"


/*����ģʽ*/
//1. �������ʵ���๲ͬ�ĳ������
class Isubject {
public:
    virtual void process() = 0;
};

//2. ʵ����
class RealSubject :public Isubject {
public:
    void process() {
        cout << "����RealSubject�Ĵ���" << endl;
    }
};

//3. ������
class ProxySubject :public Isubject {
public:
    void process() {
        cout << "����Proxy����ӷ���RealSubject --> ";
        RealSubject* realSubject = new RealSubject();
        realSubject->process();
    }
};