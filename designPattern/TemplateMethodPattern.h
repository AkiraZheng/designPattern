#pragma once
#include "header.h"

// ����⿪����Ա
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
        if (step2()) {//֧�ֱ仯 ==> �麯���Ķ�̬����
            step3();
        }
        for (int i = 0; i < 4; i++) {
            step4();//֧�ֱ仯 ==> �麯���Ķ�̬����
        }
        step5();
    }
    virtual bool step2() = 0;
    virtual void step4() = 0;
    virtual ~Library() {};
};


// Ӧ�ó��򿪷���Աʵ��Application
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
