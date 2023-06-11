#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[41];
	arr[1] = arr[2] = 1;

	for(int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[n] << " " << n - 2;
	return  0;
}



//int arr[41];
//int FibCnt = 0;
//int FibonacciCnt = 0;
//
//int Fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		FibCnt++;
//		return 1;
//	}
//	else
//		return Fib(n - 1) + Fib(n - 2);
//}
//
//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		arr[n] = 1;
//		return arr[n];
//	}
//
//	if (arr[n] != 0)
//		return arr[n];
//
//	arr[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
//	FibonacciCnt++;
//	return arr[n];
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	int n;
//	cin >> n;
//
//	Fib(n);
//	Fibonacci(n);
//
//	cout << FibCnt << " " << FibonacciCnt << "\n";
//
//	return 0;
//}