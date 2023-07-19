#include <iostream>
#include <string>

using namespace std;

int Factorial(int n)
{
	if (n == 0)
		return 1;
	if (n > 2)
		n *= Factorial(n - 1);
	return n;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	cout << Factorial(N) / (Factorial(N - K) * Factorial(K));

	return 0;
}