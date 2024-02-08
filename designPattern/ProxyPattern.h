#pragma once
#include "header.h"


/*代理模式*/
//1. 代理类和实际类共同的抽象基类
class Isubject {
public:
    virtual void process() = 0;
};

//2. 实际类
class RealSubject :public Isubject {
public:
    void process() {
        cout << "来自RealSubject的处理" << endl;
    }
};

//3. 代理类
class ProxySubject :public Isubject {
public:
    void process() {
        cout << "采用Proxy来间接访问RealSubject --> ";
        RealSubject* realSubject = new RealSubject();
        realSubject->process();
    }
};