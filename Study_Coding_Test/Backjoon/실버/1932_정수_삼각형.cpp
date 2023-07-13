#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int tri[501][501];
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			cin >> tri[i][j];

	/*
	 dp[0][0] = 7
	 dp[1][0] = 7+3		dp[1][1] = 7+8
	 dp[2][0] = 7+3+8	dp[2][1] = max(0,1)	dp[2][2] = 7+8+0
	 */
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + tri[i][j];
			else if (i == j)
				dp[i][j] = dp[i - 1][j - 1] + tri[i][j];
			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
	}

	int maxDP = dp[n - 1][0];
	for(int i = 1; i < n; i++)
		maxDP = max(maxDP, dp[n - 1][i]);

	cout << maxDP;

	return 0;
}