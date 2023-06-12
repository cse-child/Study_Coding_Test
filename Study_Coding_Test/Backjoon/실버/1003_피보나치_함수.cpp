#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int fib[41] = { 0, 1, 1,};

int fibonacci(int n)
{
	if (n == 0 || n == 1 || fib[n] != 0)
		return fib[n];

	fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return fib[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	vector<int> nums(T);
	for (int& num : nums)
		cin >> num;

	/* 0 �� 1 Ƚ���� ��Ģ ã�� */
	// N = 0 : 1 0
	// N = 1 : 0 1
	// N = 2 : 1 1
	// N = 3 : 1 2
	// N = 4 : 2 3
	// N = 5 : 3 5
	
	// ��Ģ: 1�� ��µǴ� Ƚ���� �Ǻ���ġ ���� �״�ΰ� ��µ�
	// 0�� ��µǴ� Ƚ���� 1�������� �Ǻ���ġ ���� �״�ΰ� ��µ�
	// ��, 0�� Fibonacci(N-1)�� ����ϰ�, 1�� Fibonacci(N)�� �����

	/* ����Լ� ���� */
	//for(int num : nums)
	//{
	//	if (num == 0)
	//		cout << "1 0\n";
	//	else
	//		cout << fibonacci(num - 1) << " " << fibonacci(num) << "\n";
	//}

	/* for�� ���� */
	for (int i = 3; i < 41; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (int num : nums)
	{
		if (num == 0)
			cout << "1 0\n";
		else
			cout << fib[num - 1] << " " << fib[num] << "\n";
	}
	return 0;
}