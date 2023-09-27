#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a = 100;

	cout << a << endl;
	int* ptr1;
	ptr1 = reinterpret_cast<int*>(a);

	cout << ptr1 << endl; // 16Áø¼ö

	int arr[3] = { 1,2,3 };
	void* temp = arr + 1;
	unsigned int val = reinterpret_cast<unsigned int>(temp);
	cout << endl << val << endl;

	int ttemp1 = 150;
	float& ttemp2 = reinterpret_cast<float&>(ttemp1);
	cout << endl << ttemp2 << endl;

	char c = '1';
	int* intptr = reinterpret_cast<int*>(c);
	cout << endl << intptr << endl;

	int* pp = new int(100);
	char cc = reinterpret_cast<char>(pp);
	
	cout << endl << pp << endl;
	cout << cc << endl;

	return 0;
}