#include <iostream>

using namespace std;

class A
{
public:
	virtual void Print() = 0;
};

class B : public A
{
public:
	void Print() override
	{
		cout << "Call B Print" << endl;
	}
};

class C : public A
{
public:
	void Print() override
	{
		cout << "Call C Print" << endl;
	}
};

class D : public B, public C
{
};

int main()
{
	D* obj = new D();

	obj->Print();

	/* ���� ����� �ذ� ��� */
	// 1. ������ ���� �����ڸ� �̿��� ����� ȣ��
	obj->B::Print();
	obj->C::Print();

	// 2. dynamic_cast�� Ȱ���� �ٿ�ĳ���� �� ȣ��
	B* obj2 = dynamic_cast<B*>(obj);
	obj2->Print();

	return 0;
}

