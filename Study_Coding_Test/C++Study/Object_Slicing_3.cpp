#include <iostream>
using namespace std;

class Base {
protected:
	int i;

public:
	Base operator =(const Base &other) = delete;

	Base(int a) { i = a; }
	virtual void display()
	{
		cout << "Base Class Object's i: " << i << endl;
	}

protected:
	Base(const Base &other) = default;

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

int main()
{
	Derived d(20, 30);
	Derived dd{d};

	dd.display();


	//Base b = d;
	//b.display();
	
	return 0;
}