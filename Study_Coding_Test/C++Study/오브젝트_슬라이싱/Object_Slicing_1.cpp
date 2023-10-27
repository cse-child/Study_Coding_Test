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

// Global method, Base class
// object is passed by value
void somefunc(Base obj)
{
	obj.display();
}

int main()
{
	Base b(10);
	Derived d(20, 30);
	somefunc(b);

	// Object Slicing, dÀÇ j ¸â¹ö°¡ ½½¶óÀÌ½Ì µÈ´Ù!
	somefunc(d);
	return 0;
}