#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> Weights(N+1);
	vector<int> Values(N+1);
	for(int i = 1; i <= N; i++)
		cin >> Weights[i] >> Values[i];

	vector<vector<int>> dp(N + 1, vector<int>(K + 1));
	for(int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= Weights[i]) // ¡Ú »©¸ÔÁö¸»ÀÚ!!!!!
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Weights[i]] + Values[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}