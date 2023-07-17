#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(long long n)
{
	if (n <= 1) return false;

	for(int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) 
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testCase;
	cin >> testCase;

	for(int t = 0; t < testCase; t++)
	{
		long long result = 0;
		long long n;
		cin >> n;

		while (!IsPrime(n))
			n++;
		cout << n << '\n';
	}

	return 0;
}