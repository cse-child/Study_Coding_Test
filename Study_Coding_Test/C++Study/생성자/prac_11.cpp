#include<iostream>
using namespace std;

class Test
{
public:
	Test(Test &t) { }
	Test() { }
};

Test fun()
{
	cout << "fun() Calledn";
	Test t;
	return t;
}

int main()
{
	Test t1;
	//Test t2 = fun();
	Test t2;
	t2 = fun();
	return 0;
}

// 결과
// Test t2 = fun(); 에서 컴파일러 에러 발생

// 선언해놓은 복사생성자 Test(Test& t)에서 const 키워드를 붙이지 않아 발생하는 오류이다.
// fun() 함수는 Test 객체를 반환하는데, 이러한 임시 개체를 const가 아닌 참조에 바인딩할 수 없기 때문이다.

// 따라서, 오류를 없애고 싶다면 Test(const Test &t)처럼 "const" 키워드를 추가하거나,
// Test t2; t2 = fun(); 으로 나눠 복사생성자가 아닌, 암시적 이동생성자가 호출되도록 만들면 된다.