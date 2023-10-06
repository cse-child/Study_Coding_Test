#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int i = 0, int j = 0) { x = i; y = j; }
	int getX() { return x; }
	int getY() { return y; }
};

int main()
{
	Point p1;
	Point p2 = p1;
	cout << "x = " << p2.getX() << " y = " << p2.getY();
	return 0;
}

// 결과
// x = 0 y = 0 출력

// 이전 prac_4 클래스와 달리, Point 클래스의 기본생성자가 선언되어 있고
// 디폴트 매개변수로 x와 y이 초기화 되므로, x와 y의 값이 쓰레기 값이 아닌, 0으로 잘 출력된다.

// Point p2 = p1;에 필요한 복사생성자는 암시적으로 생성되어 사용된다. 에러x