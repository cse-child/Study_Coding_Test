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

// ���
// GeeksQuiz  GeeksQuiz

// String Ŭ�������� String �����ڸ� ����Ǿ��ְ�, String s2 = s1�� �ʿ���
// ��������ڴ� ���� ���ǵǾ� ���� �ʴ�.
// ����, �Ͻ��� ��������ڷ� �����Ͱ� ����Ǹ鼭 "���� ����"�� ����ȴ�.

// String Ŭ�������� char* str�� ������ ������ �����Ƿ�, ���� ���� ��
// s1 ��ü�� s2 ��ü�� ������ str ������ �ּҸ� ����Ű�� �ִ�.

// ����, s1.change �Լ��� ���� str ������ ���ĺ��� �ٲٸ�, ������ �ּҸ� ����Ű��
// s2 ��ü�� str ������ �ٲ�� �� ���� ��� ��� ����� G �� ���´�.