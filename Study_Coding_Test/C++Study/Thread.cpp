#include <iostream>
#include <thread>

using namespace std;

void func_1()
{
	for (int i = 0; i < 10; i++)
		cout << "thread-1 작동중 : " << i+1 << "번째" << endl;
}

void func_2()
{
	for (int i = 0; i < 10; i++)
		cout << "thread-2 작동중: " << i + 1 << "번째" << endl;
}

void func_3()
{
	for (int i = 0; i < 10; i++)
		cout << "thread-3 작동중: " << i + 1 << "번째" << endl;
}

int main()
{
	thread th1(func_1);
	thread th2(func_2);
	thread th3(func_3);

	//th1.join();
	//cout << "thread-1 join 끝" << endl;
	//th2.join();
	//th3.join();

	th1.detach();
	th2.detach();
	th3.detach();
	cout << "메인 함수 종료" << endl;

	return 0;
}