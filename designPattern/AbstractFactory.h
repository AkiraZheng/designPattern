#pragma once
#include "header.h"

namespace AbstractFactor {
	/*手机产品类的设计*/
	class Phone {
		// 产品基类
	public:
		Phone(string name) :_phone_name(name) {};
		virtual void show() = 0;
		virtual ~Phone() {}; //基类应该被声明为虚析构函数
	protected:
		string _phone_name;
	};
	class Phone_Iphone :public Phone {
		// 产品派生类
	public:
		Phone_Iphone(string name) :Phone(name) {};
		void show() {
			cout << "手机工厂生产具体产品: " << _phone_name << endl;
		}
	};
	class Phone_Huawei :public Phone {
		// 产品派生类
	public:
		Phone_Huawei(string name) :Phone(name) {};
		void show() {
			cout << "手机工厂生产具体产品: " << _phone_name << endl;
		}
	};

	/*手机壳产品类的设计*/
	class PhoneShell {
		// 产品基类
	public:
		PhoneShell() {};
		virtual void display() = 0;
		virtual ~PhoneShell() {}; //基类应该被声明为虚析构函数
	};
	class PhoneShell_Iphone :public PhoneShell {
		// 产品派生类
	public:
		PhoneShell_Iphone() {};
		void display() {
			cout << "手机壳工厂生产具体产品: Iphone壳" << endl;
		}
	};
	class PhoneShell_Huawei :public PhoneShell {
		// 产品派生类
	public:
		PhoneShell_Huawei() {};
		void display() {
			cout << "手机壳工厂生产具体产品: Huawei壳" << endl;
		}
	};


	/*工厂类的设计*/
	class AbstractFactory {
		// 抽象工厂类
	public:
		virtual Phone* createPhone() = 0;
		virtual PhoneShell* createPhoneShell() = 0;
		virtual ~AbstractFactory() {}; //基类应该被声明为虚析构函数
	};
	class PhoneFactory_Iphone :public AbstractFactory {
		// 具体苹果工厂类
	public:
		Phone* createPhone() {
			return new Phone_Iphone("Iphone");
		}
		PhoneShell* createPhoneShell() {
			return new PhoneShell_Iphone();
		}
	};
	class PhoneFactory_Huawei :public AbstractFactory {
		// 具体华为工厂类
	public:
		Phone* createPhone() {
			return new Phone_Huawei("Huawei");
		}
		PhoneShell* createPhoneShell() {
			return new PhoneShell_Huawei();
		}
	};
}
