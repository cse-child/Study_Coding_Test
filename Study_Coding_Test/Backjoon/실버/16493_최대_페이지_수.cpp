#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M; // NÀÏ, M°³ Ã©ÅÍ
	cin >> N >> M;
	vector<int> days(M + 1);
	vector<int> pages(M + 1);
	for(int i = 1; i <= M; i++)
		cin >> days[i] >> pages[i];

	vector<vector<int>> dp(M+1, vector<int>(N+1));
	for(int i = 1; i <= M; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if (j >= days[i])
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - days[i]] + pages[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[M][N];
	return 0;
}