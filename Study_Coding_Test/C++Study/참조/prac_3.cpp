#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	int& ref = x;
	ref = 20;
	cout << "x = " << x << endl;
	x = 30;
	cout << "ref = " << ref << endl;
	return 0;
}

/*

결과
x = 20
ref = 30

ref 변수가 x를 참조한 순간, 둘 중 하나를 변경하면 다른 항목도 변경된다.
 
 */