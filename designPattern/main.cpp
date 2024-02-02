#include "header.h"
#include "SingletonPattern.h"

/*���ģʽ1������ģʽ*/
//����ģʽ�����ⶨ�壬main��ʼִ��ǰ���ö���ʹ�����
SingletonHungry* SingletonHungry::instance = new SingletonHungry();
void testSingletonHungry()
{
    cout << "origin->getNum() = " << SingletonHungry::getInstance()->getNum() << endl;
    SingletonHungry* p1 = SingletonHungry::getInstance();
    SingletonHungry* p2 = SingletonHungry::getInstance();
    p1->resetNum(20);
    cout << "p1->getNum() = " << p1->getNum() << endl;
    cout << "p2->getNum() = " << p2->getNum() << endl;
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

//��������1���̲߳���ȫ�ķ���
SingletonLazy1* SingletonLazy1::instance = nullptr;
void testSingletonLazy1()
{
    SingletonLazy1* p1 = SingletonLazy1::getInstance();
    SingletonLazy1* p2 = SingletonLazy1::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

//��������2��DCL˫�ؼ�����ʽ-�̰߳�ȫ�ķ���
volatile SingletonLazy2_DCL* SingletonLazy2_DCL::instance = nullptr;
mutex SingletonLazy2_DCL::mtx;// ��̬��Ա������Ҫ�������ʼ��
void testSingletonLazy2_DCL()
{
    volatile SingletonLazy2_DCL* p1 = SingletonLazy2_DCL::getInstance();
    volatile SingletonLazy2_DCL* p2 = SingletonLazy2_DCL::getInstance();
    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
}

////��������3������call_once����
//SingletonLazy3_callOnce* SingletonLazy3_callOnce::instance = nullptr;
//void testSingletonLazy3_callOnce()
//{
//    SingletonLazy3_callOnce* p1 = SingletonLazy3_callOnce::getInstance();
//    SingletonLazy3_callOnce* p2 = SingletonLazy3_callOnce::getInstance();
//    cout << "p1 = " << p1 << endl;
//    cout << "p2 = " << p2 << endl;
//}

int main() {
	/*
	* ���ģʽ1������ģʽ
	*/
    //testSingletonHungry();
    //testSingletonLazy1();
    //testSingletonLazy2_DCL();

    return 0;
}