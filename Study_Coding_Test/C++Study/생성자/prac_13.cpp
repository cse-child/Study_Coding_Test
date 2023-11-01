#include <iostream>

using namespace std;

class Base {
public:
	Base() { std::cout << "Base의 생성자 호출\n"; }
	virtual ~Base() { std::cout << "Base의 소멸자 호출\n"; }
};

class Derived : public Base {
public:
	Derived() { std::cout << "Derived의 생성자 호출\n"; }
	~Derived() { std::cout << "Derived의 소멸자 호출\n"; }
};

int main() {
	Base* base = new Derived();
	delete base;
	return 0;
}
