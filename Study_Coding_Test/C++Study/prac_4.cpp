#include<iostream>
using namespace std;

class Empty {};

class Temp
{
	int a;
};

int main()
{
	cout << sizeof(Empty) << endl; // ��� ���: 1

	cout << sizeof(Temp) << endl; // ��� ���: 4

	return 0;
}

https://www.geeksforgeeks.org/c-plus-plus-gq/class-and-object-gq/

// �� Ŭ������ ����ü�� ũ��� �Լ��� ȣ���ϱ� ���� �ּ����� 1����Ʈ�� �ʿ��ϴ�.
// 1����Ʈ�� �־�� �����Ϸ��� Ŭ������ ������ �ּҸ� �ĺ��� �� �ְ�
// Ŭ������ �ν��Ͻ�ȭ�� �� �Ҵ�Ǵ� ������ �Ǵ°��̴�.