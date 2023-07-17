#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int Max = 123456 * 2;
bool check[Max+1];

int GetPrimeCount(int n)
{
	int cnt = 0;
	for(int i = n+1; i <= 2*n; i++)
	{
		if (!check[i])
			cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	check[0] = check[1] = true;

	for (int i = 2; i <= sqrt(Max); i++)
	{
		if (!check[i])
		{
			for (int j = i + i; j <= Max; j += i)
				check[j] = true;
		}
	}

	while(true)
	{
		int input;
		cin >> input;
		if (input == 0) break;

		cout << GetPrimeCount(input) << '\n';
	}

	return 0;
}