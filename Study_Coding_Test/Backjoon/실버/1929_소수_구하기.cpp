#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M, N;
	cin >> M >> N;

	vector<bool> check(N+1);
	check[0] = check[1] = true;
	for(int i = 2; i <= sqrt(N); i++)
	{
		if(!check[i])
		{
			for (int j = i + i; j <= N; j += i)
				check[j] = true;
		}
	}

	for(int i = M; i <= N; i++)
	{
		if (!check[i])
			cout << i << '\n';
	}

	return 0;
}