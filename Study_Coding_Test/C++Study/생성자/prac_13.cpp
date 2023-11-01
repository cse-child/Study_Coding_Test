#include <iostream>

using namespace std;

class Base {
public:
	Base() { std::cout << "Base�� ������ ȣ��\n"; }
	virtual ~Base() { std::cout << "Base�� �Ҹ��� ȣ��\n"; }
};

class Derived : public Base {
public:
	Derived() { std::cout << "Derived�� ������ ȣ��\n"; }
	~Derived() { std::cout << "Derived�� �Ҹ��� ȣ��\n"; }
};

int main() {
	Base* base = new Derived();
	delete base;
	return 0;
}
