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

// 결과
// 컴파일 에러

// Point(const Point p)는 복사생성자의 선언 형식인데,
// Point 매개변수를 참조값 &이 아닌 값으로 전달하여 컴파일 에러가 발생하게 된다.
// 따라서 const Point p 부분에 const Point& p 로 참조값만 넣으면
// 10 으로 정상적인 출력이 이루어진다.