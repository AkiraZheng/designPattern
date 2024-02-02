#pragma once
#include "header.h"

/*����ģʽ*/
class SingletonHungry
{
private:
    SingletonHungry() {};              // ���캯��˽�л�
    static SingletonHungry* instance; // ��̬��Ա����

    // ��ֹ��������͸�ֵ����
    SingletonHungry(const SingletonHungry&) = delete;
    SingletonHungry& operator=(const SingletonHungry&) = delete;

    // ������
    int test_num = 10;

public:
    static SingletonHungry* getInstance()
    {
        return instance;
    }

    // ������
    void resetNum(int num)
    {
        test_num = num;
    }

    int getNum()
    {
        return test_num;
    }
};

/*����ʽ����1���̲߳���ȫ�ķ�ʽ*/
class SingletonLazy1
{
private:
    SingletonLazy1() {};              // ���캯��˽�л�
    static SingletonLazy1* instance; // �������ʱ����������ʵ��

    // ��ֹ��������͸�ֵ����
    SingletonLazy1(const SingletonLazy1&) = delete;
    SingletonLazy1& operator=(const SingletonLazy1&) = delete;

public:
    static SingletonLazy1* getInstance()
    {
        if (instance == NULL)
            instance = new SingletonLazy1(); // ��һ�ε���ʱ��������ʵ��
        return instance;
    }
};

/*��������2���̰߳�ȫ�ķ�ʽ*/
class SingletonLazy2_DCL
{
private:
    SingletonLazy2_DCL() {};                       // ���캯��˽�л�
    volatile static SingletonLazy2_DCL* instance; // ������volatile����
    static mutex mtx;
public:
    volatile static SingletonLazy2_DCL* getInstance() // ��Ҫ����ͬ����������֤�̰߳�ȫ
    {
        if (instance == nullptr)
        {                                          // ��һ�μ��
            mtx.lock(); // ����
            if (instance == nullptr)
            {                              // �ڶ��μ��,��ֹ����߳�ͬʱ�����ٽ���
                instance = new SingletonLazy2_DCL(); // ����ʵ��
            }
            mtx.unlock(); // ����
        }
        return instance;
    }
};

///*��������3��C++11�е�call_once*/
//class SingletonLazy3_callOnce {
//private:
//    static SingletonLazy3_callOnce* instance;
//    static std::once_flag onceFlag;
//
//    // ˽�л����캯��
//    SingletonLazy3_callOnce() {}
//
//    // ��ֹ��������͸�ֵ����
//    SingletonLazy3_callOnce(const SingletonLazy3_callOnce&) = delete;
//    SingletonLazy3_callOnce& operator=(const SingletonLazy3_callOnce&) = delete;
//
//public:
//    // ��ȡ��������ĺ���
//    static SingletonLazy3_callOnce* getInstance() {
//        std::call_once(onceFlag, []() {
//            instance = new SingletonLazy3_callOnce();
//        });
//        return instance;
//    }
//};