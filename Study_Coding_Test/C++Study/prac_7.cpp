#include <iostream>
using namespace std; 

class Test
{
	
public:
		Test() { cout << "Hello from Test() "; }
} a;

int main()
{
	cout << "Main Started "; 
	return 0; 
}

// 결과
// Hello from Test() Main Started

// Test 클래스의 선언 가장 뒤에 a; 변수를 전역 변수를 선언하였다.
// 이처럼, 클래스의 정의와 동시에 생성되는 방식은 C++언어에서 허용되었고,
// 이를 "인라인 객체 생성" 혹은, "인라인 객체 선언"이라고 부른다.

// 변수 a가 전역변수 이기 때문에, main 함수가 호출되기 전에 먼저 호출된다.