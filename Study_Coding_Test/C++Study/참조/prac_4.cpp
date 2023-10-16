#include<iostream>
using namespace std;

class Empty {};

class Temp
{
	int a;
};

int main()
{
	cout << sizeof(Empty) << endl; // 출력 결과: 1

	cout << sizeof(Temp) << endl; // 출력 결과: 4

	return 0;
}

https://www.geeksforgeeks.org/c-plus-plus-gq/class-and-object-gq/

// 빈 클래스나 구조체의 크기는 함수를 호출하기 위한 최소한의 1바이트가 필요하다.
// 1바이트가 있어야 컴파일러가 클래스의 고유한 주소를 식별할 수 있고
// 클래스가 인스턴스화될 때 할당되는 공간이 되는것이다.