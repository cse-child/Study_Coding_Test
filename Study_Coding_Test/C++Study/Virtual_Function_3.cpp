#include <iostream>

using namespace std;

class A
{
public:
	virtual void Print() = 0;
};

class B : virtual public A
{
public:
	void Print() override
	{
		cout << "Call B Print" << endl;
	}
};

class C : virtual public A
{
public:
	void Print() override
	{
		cout << "Call C Print" << endl;
	}
};

class D : public B, public C
{
public:
	void Print() override
	{
		cout << "Call D Print" << endl;
	}
};

int main()
{
	D* obj = new D();
	B* test = obj;
	obj->Print();

	C* obj2 = new C();

	return 0;
}

