#pragma once
#include "header.h"
namespace FactoryMethod_SimpleFactory {
    /*��Ʒ������*/
    class Phone {
        // ��Ʒ����
    public:
        Phone(string name) :_phone_name(name) {};
        virtual void show() = 0;
    protected:
        string _phone_name;
    };
    class Iphone :public Phone {
        // ��Ʒ������
    public:
        Iphone(string name) :Phone(name) {};
        void show() {
            cout << "I have a phone named: " << _phone_name << endl;
        }
    };
    class HuaWei :public Phone {
        // ��Ʒ������
    public:
        HuaWei(string name) :Phone(name) {};
        void show() {
            cout << "I have a phone named: " << _phone_name << endl;
        }
    };

    /*����������*/
    class PhoneFactory {
        // ������
    public:
        enum phone_type {
            IPHONE,
            HUAWEI
        };
        Phone* createPhone(int type) {
            switch (type)
            {
            case IPHONE:
                return new Iphone("iphone");
            case HUAWEI:
                return new HuaWei("huawei");
            default:
                return nullptr;
            }
        }
    };
}

