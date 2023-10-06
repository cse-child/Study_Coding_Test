#include<iostream>
using namespace std;

class Point {
public:
	Point() { cout << "Constructor called"; }
};

int main()
{
	Point t1, *t2;
	// 결과: Point t1에 대한 생성자만 1회 호출됨
	// *t2는 클래스 객체가 아닌 포인터 변수로써만 선언되므로
	// 생성자가 호출되지 않는다.

	// *t2와 같이 포인터를 선언할 때는 Point 클래스의 객체를 가리키기 위한 메모리만 할당할 뿐,
	// 객체 자체를 생성하는 것은 아니기 때문에 생성자가 호출되지 않는다.
	// 포인터 변수를 통해 생성자를 호출하려면 new Point(); 같은 동적할당을 통해 객체를 생성해주어야 한다.


	Point s1, s2, s3;
	// 결과: Point 클래스의 생성자가 3번 호출됨

	// 이때 생성되는 객체들은 포인터 변수가 아니므로, 스택 메모리 영역에 생성된다.

	return 0;
}