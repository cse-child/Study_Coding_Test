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

	/* 다중 상속의 해결 방법 */
	// 1. 스코프 지정 연산자를 이용한 명시적 호출
	obj->B::Print();
	obj->C::Print();

	// 2. dynamic_cast를 활용한 다운캐스팅 후 호출
	B* obj2 = dynamic_cast<B*>(obj);
	obj2->Print();

	return 0;
}

