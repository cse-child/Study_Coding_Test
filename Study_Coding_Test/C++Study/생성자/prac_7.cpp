#include <iostream>
using namespace std; 

class Test
{
	
public:
		Test() { cout << "Hello from Test() "; }
} a;

int main()
{
	cout << "Main Started "; 
	return 0; 
}

// ���
// Hello from Test() Main Started

// Test Ŭ������ ���� ���� �ڿ� a; ������ ���� ������ �����Ͽ���.
// ��ó��, Ŭ������ ���ǿ� ���ÿ� �����Ǵ� ����� C++���� ���Ǿ���,
// �̸� "�ζ��� ��ü ����" Ȥ��, "�ζ��� ��ü ����"�̶�� �θ���.

// ���� a�� �������� �̱� ������, main �Լ��� ȣ��Ǳ� ���� ���� ȣ��ȴ�.