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

	/* 0 과 1 횟수의 규칙 찾기 */
	// N = 0 : 1 0
	// N = 1 : 0 1
	// N = 2 : 1 1
	// N = 3 : 1 2
	// N = 4 : 2 3
	// N = 5 : 3 5
	
	// 규칙: 1이 출력되는 횟수는 피보나치 수열 그대로가 출력됨
	// 0이 출력되는 횟수는 1에서부터 피보나치 수열 그대로가 출력됨
	// 즉, 0은 Fibonacci(N-1)을 출력하고, 1은 Fibonacci(N)을 출력함

	/* 재귀함수 버전 */
	//for(int num : nums)
	//{
	//	if (num == 0)
	//		cout << "1 0\n";
	//	else
	//		cout << fibonacci(num - 1) << " " << fibonacci(num) << "\n";
	//}

	/* for문 버전 */
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