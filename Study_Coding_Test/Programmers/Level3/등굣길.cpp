#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
	for (int i = 0; i < puddles.size(); i++)
		dp[puddles[i][1]][puddles[i][0]] = -1;

	dp[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1) continue;
			if (dp[i][j] == -1) continue;

			int a = 0, b = 0;
			if (dp[i][j - 1] != -1)
				a = dp[i][j - 1];
			if (dp[i - 1][j] != -1)
				b = dp[i - 1][j];

			dp[i][j] = (a + b) % 1000000007;
		}
	}
	return dp[n][m];
}

int main()
{
	cout << solution(4, 3, { {2,2} });
}