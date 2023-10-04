#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(const Point &p) { x = p.x; y = p.y; }
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

// Point 클래스에 매개변수가 없는 기본생성자가 선언되어 있지 않으므로 컴파일 에러 발생
// 해당 코드는 복사생성자만 정의되어 있을 뿐, Point() 의 기본생성자가 없다.

// 또 한가지 볼 것은, Point 객체의 x, y값을 따로 초기화하지 않았기 때문에
// 생성자가 존재하여서 cout 구문을 출력한다 해도 x = 0 y = 0이 아닌 쓰레기 값이 출력될 것이다.