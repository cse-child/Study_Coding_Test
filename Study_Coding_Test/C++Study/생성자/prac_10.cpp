#include <iostream>
using namespace std;

class Test
{
private:
	int x;
public:
	//explicit Test(int i)
	Test(int i)
	{
		x = i;
		cout << "Called" << endl;
	}
};

int main()
{
	Test t(20);
	t = 30; // conversion constructor is called here.
	return 0;
}

// 결과
// Called Called

// Test 생성자는 1개의 매개변수 i를 받는다.
// 이때 t = 30; 이라는 구문에서 변환 생성자가 호출되어 Test(30);으로 암시적 변환되었고
// 그로인해 Called 출력구문이 한번 더 호출된 것이다.

// 컴파일러가 자동 형변환을 해주기 때문에 발생하는 것

//만약 Test(int i) 생성자 앞에 "explicit" 키워드를 붙여주면 변환 생성자의 무작위 호출이 막아져
//컴파일 에러가 발생한다!


////////////////////// 다른 변환생성자 예제 ///////////////////////////
/*
class CMyData
{
public:
	CMyData(int x) : nData(x)
	{
		cout << "변환 생성자 호출" << endl;
	}

private:
	int nData;
};

void TestFunc(const CMyData &rhs) // 분명 TestFunc 함수는 매개값으로 CMyData 객체의 참조를 받는다.
{
	cout << "TestFunc(): " << rhs.GetData() << endl;
}

int main()
{
	CMyData a(100);
	TestFunc(a); // 일반적인 함수 호출 경우

	TestFunc(1000); // 인자값으로 1000을 넣었는데도 컴파일 오류가 발생하지 않는다.
	return 0;
}
 
 */

