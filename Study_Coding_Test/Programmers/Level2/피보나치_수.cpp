#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long fib[100001];

int solution(int n) {
	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= 100000; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1234567;

	return fib[n];
}

int main()
{
	cout << solution(100000);
	return 0;
}