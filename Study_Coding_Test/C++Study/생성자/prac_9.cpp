#include<iostream>
using namespace std;

class Point {
	int x;
public:
	Point(int x) { this->x = x; }
	Point(const Point p) { x = p.x; }
	int getX() { return x; }
};

int main()
{
	Point p1(10);
	Point p2 = p1;
	cout << p2.getX();

	return 0;
}

// ���
// ������ ����

// Point(const Point p)�� ����������� ���� �����ε�,
// Point �Ű������� ������ &�� �ƴ� ������ �����Ͽ� ������ ������ �߻��ϰ� �ȴ�.
// ���� const Point p �κп� const Point& p �� �������� ������
// 10 ���� �������� ����� �̷������.