#include<iostream>
using namespace std;

class Test
{
public:
	Test(Test &t) { }
	Test() { }
};

Test fun()
{
	cout << "fun() Calledn";
	Test t;
	return t;
}

int main()
{
	Test t1;
	//Test t2 = fun();
	Test t2;
	t2 = fun();
	return 0;
}

// ���
// Test t2 = fun(); ���� �����Ϸ� ���� �߻�

// �����س��� ��������� Test(Test& t)���� const Ű���带 ������ �ʾ� �߻��ϴ� �����̴�.
// fun() �Լ��� Test ��ü�� ��ȯ�ϴµ�, �̷��� �ӽ� ��ü�� const�� �ƴ� ������ ���ε��� �� ���� �����̴�.

// ����, ������ ���ְ� �ʹٸ� Test(const Test &t)ó�� "const" Ű���带 �߰��ϰų�,
// Test t2; t2 = fun(); ���� ���� ��������ڰ� �ƴ�, �Ͻ��� �̵������ڰ� ȣ��ǵ��� ����� �ȴ�.