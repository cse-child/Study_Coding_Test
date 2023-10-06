#include<iostream>
using namespace std;

class Point {
public:
	Point() { cout << "Normal Constructor called\n"; }
	Point(const Point &t) { cout << "Copy constructor called\n"; }
};

int main()
{
	Point *t1, *t2; // 생성자 호출 X
	t1 = new Point(); // 기본생성자 Normal 호출
	t2 = new Point(*t1); // 복사생성자 Copy 호출
	Point t3 = *t1; // 복사생성자 Copy 호출
	Point t4; // 기본생성자 Normal 호출
	t4 = t3; // 대입연산자 호출되어야 하는데 만들어놓은 함수가 없어서 출력 X

	// 출력 결과
	//Normal Constructor called
	//Copy constructor called
	//Copy constructor called
	//Normal Constructor called

	return 0;
}