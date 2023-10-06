#include<iostream>
using namespace std;

class Point {
public:
	Point() { cout << "Normal Constructor called\n"; }
	Point(const Point &t) { cout << "Copy constructor called\n"; }
};

int main()
{
	Point *t1, *t2; // ������ ȣ�� X
	t1 = new Point(); // �⺻������ Normal ȣ��
	t2 = new Point(*t1); // ��������� Copy ȣ��
	Point t3 = *t1; // ��������� Copy ȣ��
	Point t4; // �⺻������ Normal ȣ��
	t4 = t3; // ���Կ����� ȣ��Ǿ�� �ϴµ� �������� �Լ��� ��� ��� X

	// ��� ���
	//Normal Constructor called
	//Copy constructor called
	//Copy constructor called
	//Normal Constructor called

	return 0;
}