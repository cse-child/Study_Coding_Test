#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
	vector<bool> check(n + 1, true);
	check[0] = check[1] = false;

	for(int i = 2; i < sqrt(n); i++)
	{
		if(check[i])
		{
			for (int j = i + i; j <= n; j += i)
				check[j] = false;
		}
	}

	return count(check.begin(), check.end(), true);
}