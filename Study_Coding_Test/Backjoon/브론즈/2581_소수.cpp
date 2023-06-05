#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <numeric>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;

	bool check[10001];
	memset(check, true, sizeof(check));
	check[0] = check[1] = false;

	vector<int> divisor;
	for (int i = 2; i <= sqrt(N); i++)
	{
		if (check[i])
		{
			for (int j = i + i; j <= N; j += i)
				check[j] = false;
		}
	}

	for (int i = M; i <= N; i++)
	{
		if (check[i])
			divisor.push_back(i);
	}

	if (divisor.empty())
		cout << -1 << endl;
	else
	{
		cout << accumulate(divisor.begin(), divisor.end(), 0) << endl;
		cout << *min_element(divisor.begin(), divisor.end()) << endl;
	}

	return 0;
}