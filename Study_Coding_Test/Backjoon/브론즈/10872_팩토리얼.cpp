#include <iostream>
#include <string>

using namespace std;

int Factorial(int n)
{
	if (n > 2)
		n *= Factorial(n - 1);
	return n;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N == 0)
		cout << "1";
	else
		cout << Factorial(N);

	return 0;
}