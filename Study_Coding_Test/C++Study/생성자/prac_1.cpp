#include <iostream>
using namespace std;

class Point {
	// public
	Point(){ cout << "Constructor called"; }
};

int main()
{
	Point t1;

	Point* t2 = new Point();

	return 0;
}

// Ŭ���� ����� ����Ʈ ���������ڰ� private �̹Ƿ�, �� �ڵ�� ������ ���� �߻�
// ���������� Point Ŭ������ �����ڰ� ��µǷ��� public ���������ڸ� �ۼ��ؾ� ��

// �׷��ٸ� public Point() �����ڸ� �Ҵ��ϰ� ����
// Point t1 = new Point(); �� �����?

// ������ ���� �߻�: new�� �̿��� �����Ҵ� �Ϸ��� Point* t1���� ��ü�� �����ؾ� ��