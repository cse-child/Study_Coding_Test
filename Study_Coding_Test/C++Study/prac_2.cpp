#include<iostream>
using namespace std;

int& fun()
{
	static int x = 10;
	return x;
}
int main()
{
	fun() = 30;
	cout << fun();
	return 0;
}


/*
 결과 : 30

 함수가 참조로 반환되면 lvalue로 사용할 수 있다.
 또한, x는 정적 변수이므로 함수 호출과 초기화 하는 static int x = 10; 에서
 변수가 공유된다. 따라서 fun() = 30이 실행될 때,
 x에는 30이 들어가 최종적으로 30으로 출력된다.


 ----다른 문제-----
 int &fun()
{
    int x = 10;
    return x;
}

위처럼 x를 정적변수가 아닌 지역변수로 선언한다면,
함수 호출이 끝나고 반환될 때, 메모리 위치가 유효하지 않게 되어
런타임 에러가 발생할 수 있다.
 
*/