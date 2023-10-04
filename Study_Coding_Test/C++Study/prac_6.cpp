#include<iostream>
#include<stdlib.h>
using namespace std;

class Test
{
public:
	Test()
	{
		cout << "Constructor called";
	}
};

int main()
{
	Test *t = (Test *)malloc(sizeof(Test));
	return 0;
}

// 결과
// Empty

// malloc과 new의 차이점 중 하나인, 생성자 호출 관련 문제이다.
// malloc을 통해 객체를 생성하면 생성자가 따로 호출되지 않는다.
// 따라서 해당 프로그램의 실행 결과는 그냥 빈 화면이다.
