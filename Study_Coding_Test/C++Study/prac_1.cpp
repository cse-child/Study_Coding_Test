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

// 클래스 멤버는 디폴트 접근지정자가 private 이므로, 위 코드는 컴파일 오류 발생
// 성공적으로 Point 클래스의 생성자가 출력되려면 public 접근지정자를 작성해야 함

// 그렇다면 public Point() 생성자를 할당하고 나서
// Point t1 = new Point(); 의 결과는?

// 컴파일 에러 발생: new를 이용해 동적할당 하려면 Point* t1으로 객체를 선언해야 함