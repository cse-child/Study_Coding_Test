#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>

using namespace std;

class String
{
	char *str;
public:
	String(const char *s);
	void change(int index, char c) { str[index] = c; }
	char *get() { return str; }
};

String::String(const char *s)
{
	int l = strlen(s);
	str = new char[l + 1];
	strcpy(str, s);
}

int main()
{
	String s1("geeksQuiz");
	String s2 = s1;
	s1.change(0, 'G');
	cout << s1.get() << " ";
	cout << s2.get();
}

// 결과
// GeeksQuiz  GeeksQuiz

// String 클래스에선 String 생성자만 선언되어있고, String s2 = s1에 필요한
// 복사생성자는 따로 정의되어 있지 않다.
// 따라서, 암시적 복사생성자로 데이터가 복사되면서 "얕은 복사"가 수행된다.

// String 클래스에는 char* str의 포인터 변수가 있으므로, 얕은 복사 시
// s1 객체와 s2 객체가 동일한 str 포인터 주소를 가리키고 있다.

// 따라서, s1.change 함수를 통해 str 변수의 알파벳을 바꾸면, 동일한 주소를 가리키는
// s2 객체의 str 변수도 바뀌어 두 번의 출력 모두 대분자 G 로 나온다.