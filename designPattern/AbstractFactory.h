#pragma once
#include "header.h"

namespace AbstractFactor {
	/*�ֻ���Ʒ������*/
	class Phone {
		// ��Ʒ����
	public:
		Phone(string name) :_phone_name(name) {};
		virtual void show() = 0;
		virtual ~Phone() {}; //����Ӧ�ñ�����Ϊ����������
	protected:
		string _phone_name;
	};
	class Phone_Iphone :public Phone {
		// ��Ʒ������
	public:
		Phone_Iphone(string name) :Phone(name) {};
		void show() {
			cout << "�ֻ��������������Ʒ: " << _phone_name << endl;
		}
	};
	class Phone_Huawei :public Phone {
		// ��Ʒ������
	public:
		Phone_Huawei(string name) :Phone(name) {};
		void show() {
			cout << "�ֻ��������������Ʒ: " << _phone_name << endl;
		}
	};

	/*�ֻ��ǲ�Ʒ������*/
	class PhoneShell {
		// ��Ʒ����
	public:
		PhoneShell() {};
		virtual void display() = 0;
		virtual ~PhoneShell() {}; //����Ӧ�ñ�����Ϊ����������
	};
	class PhoneShell_Iphone :public PhoneShell {
		// ��Ʒ������
	public:
		PhoneShell_Iphone() {};
		void display() {
			cout << "�ֻ��ǹ������������Ʒ: Iphone��" << endl;
		}
	};
	class PhoneShell_Huawei :public PhoneShell {
		// ��Ʒ������
	public:
		PhoneShell_Huawei() {};
		void display() {
			cout << "�ֻ��ǹ������������Ʒ: Huawei��" << endl;
		}
	};


	/*����������*/
	class AbstractFactory {
		// ���󹤳���
	public:
		virtual Phone* createPhone() = 0;
		virtual PhoneShell* createPhoneShell() = 0;
		virtual ~AbstractFactory() {}; //����Ӧ�ñ�����Ϊ����������
	};
	class PhoneFactory_Iphone :public AbstractFactory {
		// ����ƻ��������
	public:
		Phone* createPhone() {
			return new Phone_Iphone("Iphone");
		}
		PhoneShell* createPhoneShell() {
			return new PhoneShell_Iphone();
		}
	};
	class PhoneFactory_Huawei :public AbstractFactory {
		// ���廪Ϊ������
	public:
		Phone* createPhone() {
			return new Phone_Huawei("Huawei");
		}
		PhoneShell* createPhoneShell() {
			return new PhoneShell_Huawei();
		}
	};
}
