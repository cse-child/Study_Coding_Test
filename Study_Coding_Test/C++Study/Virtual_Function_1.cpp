#include <iostream>

using namespace std;

class A
{
public:
	virtual void Print()
	{
		cout << "Call A Print" << endl;
	}
};

class B
{
public:
	virtual void Print()
	{
		cout << "Call B Print" << endl;
	}
};

class C : public A, public B
{
};

int main()
{
	C* obj = new C();
	//obj->Print(); // ��ȣ�� ȣ�� ����

	return 0;
}

