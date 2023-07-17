#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int Max = 1000001;
bool check[Max];


int GetPartition(int n)
{
	int cnt = 0;
	for(int i = 0; i <= n/2; i++)
	{
		if (!check[i] && !check[n - i])
			cnt++;
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	check[0] = check[1] = true;
	for(int i = 2; i <= sqrt(Max); i++)
	{
		if(!check[i])
		{
			for (int j = i + i; j <= Max; j += i)
				check[j] = true;
		}
	}

	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		cout << GetPartition(N) << '\n';
	}

	return 0;
}