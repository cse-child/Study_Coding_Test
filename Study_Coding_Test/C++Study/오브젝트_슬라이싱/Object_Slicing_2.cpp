#include <iostream>
using namespace std;

class Base {
protected:
	int i;

public:
	Base(int a) { i = a; }
	virtual void display()
	{
		cout << "Base Class Object's i: " << i << endl;
	}
};

class Derived : public Base {
private:
	int j;

public:
	Derived(int a, int b)
		: Base(a)
	{
		j = b;
	}
	virtual void display()
	{
		cout << "Derived Class Object's i : " << i << ", j : " << j << endl;
	}
};

// ������ �Ű����� ���޹ޱ�
void somefunc(Base& obj)
{
	obj.display();
}

/* �����ͷ� �޴� ��쵵 �����ϴ�
void somefunc(Base* obj)
{
	obj->display();
} */

int main()
{
	Base b(10);
	Derived d(20, 30);
	somefunc(b);

	// Object Slicing, d�� j ����� �����̽� �ȴ�!
	somefunc(d);
	return 0;
}

