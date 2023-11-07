#include <iostream>

using namespace std;

class A
{
public:
	virtual void Print()
	{
		cout << "Call A Print" << endl;
	}

	virtual ~A(){}
};

class B
{
public:
	virtual void Print()
	{
		cout << "Call B Print" << endl;
	}

	virtual ~B(){}
};

class C : public A, public B
{
public:
	~C(){}
};

int main()
{
	C* obj = new C();
	//obj->Print(); // ��ȣ�� ȣ�� ����

	return 0;
}

