#pragma once
#include "header.h"

// 程序库开发人员
#include <iostream>
using namespace std;

class Library {
public:
    void step1() {
        cout << "Library::step1()" << endl;
    }
    void step3() {
        cout << "Library::step3()" << endl;
    }
    void step5() {
        cout << "Library::step5()" << endl;
    }
    void run() {
        step1();
        if (step2()) {//支持变化 ==> 虚函数的多态调用
            step3();
        }
        for (int i = 0; i < 4; i++) {
            step4();//支持变化 ==> 虚函数的多态调用
        }
        step5();
    }
    virtual bool step2() = 0;
    virtual void step4() = 0;
    virtual ~Library() {};
};


// 应用程序开发人员实现Application
class Application :public Library
{
public:
    bool step2() {
        cout << "Application::step2()" << endl;
        //...
        return true;
    }
    void step4() {
        cout << "Application::step4()" << endl;
    }
};
