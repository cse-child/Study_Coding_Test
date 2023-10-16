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

// 참조로 매개변수 전달받기
void somefunc(Base& obj)
{
	obj.display();
}

/* 포인터로 받는 경우도 동일하다
void somefunc(Base* obj)
{
	obj->display();
} */

int main()
{
	Base b(10);
	Derived d(20, 30);
	somefunc(b);

	// Object Slicing, d의 j 멤버가 슬라이싱 된다!
	somefunc(d);
	return 0;
}

